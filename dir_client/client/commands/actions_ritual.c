/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** functions for rituals preparation
*/

#include "client.h"
#include "ritual.h"

const ritual_t ritual_tab[] = {
	&ritual_for_level_one,
	&ritual_for_level_two,
	&ritual_for_level_three,
	NULL
};

/**
* @brief Set the stone on the floor to evolve level 4
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return the linked list
*/
static list_res_t *ritual_for_level_three(client_t *self, list_res_t *head)
{
	if (!request_std(self->sfd, head, "Set", "Set linemate") ||
	!request_std(self->sfd, head, "Set", "Set linemate") ||
	!request_std(self->sfd, head, "Set", "Set sibur") ||
	!request_std(self->sfd, head, "Set", "Set phiras"))
		return (NULL);
	return (head);
}

/**
* @brief Set the stone on the floor to evolve level 3
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return the linked list
*/
static list_res_t *ritual_for_level_two(client_t *self, list_res_t *head)
{
	if (!request_std(self->sfd, head, "Set", "Set linemate") ||
	!request_std(self->sfd, head, "Set", "Set deraumere") ||
	!request_std(self->sfd, head, "Set", "Set sibur"))
		return (NULL);
	return (head);
}

/**
* @brief Set the stone on the floor to evolve level 2
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return linked list
*/
static list_res_t *ritual_for_level_one(client_t *self, list_res_t *head)
{
	if (!request_std(self->sfd, head, "Set", "Set linemate"))
		return (NULL);
	return (head);
}

/**
* @brief Start ritual
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return linked list
*/
list_res_t *start_ritual(client_t *self, list_res_t *head)
{
	if (self->role & r_caller) {
		head = ritual_tab[self->level - 1](self, head);
		if (!head)
			return (NULL);
		if (self->level > 1)
			head = request_broadcast(self, head, 3);
		if (!request_cmd(self->sfd, head, "Incantation"))
			return (NULL);
	}
	return (head);
}

/**
* @brief Enter to ritual state
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return linked list
*/
list_res_t *enter_ritual_state(client_t *self, list_res_t *head)
{
	if (self->role & r_listener && !(self->role & r_present)) {
		if (!request_cmd(self->sfd, head, "Look"))
			return (NULL);
	} else if (!self->role) {
		self->role = r_caller;
		self->r_act = players_needed_by_ritual(self->level);
		if (!request_cmd(self->sfd, head, "Look"))
			return (NULL);
	}
	return (head);
}
