/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** functions for message handling
*/

#include "client.h"

/**
* @brief decisions took by the client when he recieve a call from another
* client
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param msg (message_t *) Struct which contains message informations
* @return list_res_t* containing the head or null if an error occurs
*/
static list_res_t *call_actions(client_t *self,
				list_res_t *head, message_t *msg)
{
	if (self->role & r_caller && self->id < msg->id &&
	self->level == msg->level) {
		if (!request_broadcast(self, head, 2)) {
			free(msg);
			return (NULL);
		}
		self->role = r_listener;
		self->r_act = msg->id;
	} if (!self->role) {
		self->role = r_listener;
		self->r_act = msg->id;
	} if ((self->role & r_listener) && msg->id == self->r_act &&
	self->state & n_ritual)
		  head = sound_reception(self, head, msg->tile);
	free(msg);
	return (head);
}

/**
* @brief decisions took by the client when the caller cancel his call
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param msg (message_t *) Struct which contains message informations
* @return list_res_t* containing the head or null if an error occurs
*/
static list_res_t *cancel_actions(client_t *self,
				list_res_t *head, message_t *msg)
{
	if (self->role & r_listener &&
	self->r_act == msg->id && self->state & n_ritual) {
		self->role = r_caller;
		self->r_act = players_needed_by_ritual(self->level);
		if (!request_broadcast_call(self, head)) {
			free(msg);
			return (NULL);
		}
	} else if (self->role & r_listener && self->r_act == msg->id) {
		self->role = 0;
		self->r_act = 0;
	}
	free(msg);
	return (head);
}

/**
* @brief decisions took by the client when a ritual is about to begin
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param msg (message_t *) Struct which contains message informations
* @return list_res_t* containing the head or null if an error occurs
*/
static list_res_t *begin_actions(client_t *self,
				list_res_t *head, message_t *msg)
{
	if (!(self->role & r_present)) {
		return (cancel_actions(self, head, msg));
	} else if (self->role & r_listener && self->role & r_present &&
	self->r_act == msg->id)
		if (!request_cmd(self->sfd, head, "Look")) {
			free(msg);
			return (NULL);
		}
	free(msg);
	return (head);
}

/**
* @brief decisions took by the caller when a client say that he is there
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param msg (message_t *) Struct which contains message informations
* @return list_res_t* containing the head or null if an error occurs
*/
static list_res_t *there_actions(client_t *self,
			list_res_t *head, message_t *msg)
{
	if ((self->role & r_caller) && msg->tile == 0) {
		self->r_act--;
		if (self->r_act == 0 && !request_broadcast(self, head, 3)) {
			free(msg);
			return (NULL);
		}
	}
	free(msg);
	return (head);
}

/**
* @brief parse the message and associate it to an action
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* containing the head or null if an error occurs
*/
list_res_t *handle_message(client_t *self, list_res_t *head)
{
	message_t *msg = parse_message(head->res, self->team);

	if (!msg)
		return (head);
	switch (msg->action) {
	case 1:
		return (call_actions(self, head, msg));
	case 2:
		return (cancel_actions(self, head, msg));
	case 3:
		return (begin_actions(self, head, msg));
	case 4:
		return (there_actions(self, head, msg));
	}
	free(msg);
	return (head);
}
