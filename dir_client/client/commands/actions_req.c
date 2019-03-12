/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** requests functions
*/

#include "client.h"

/**
* @brief Add the new command in the linked list and write the new command on
* the server
*
* @param sfd (int) It's the server's fd
* @param head (list_res_t *) Linked list which contains commands and responses
* @param cmd (char *) The command that we want to put in the linked list and
* write
* @return list_res_t* the linked list with new command
*/
list_res_t *request_cmd(int sfd, list_res_t *head, char *cmd)
{
	if (!add_list_cmd(head, cmd) || dprintf(sfd, "%s\n", cmd) == -1)
		return (NULL);
	return (head);
}

/**
* @brief Request with different message and different name
*
* @param sfd (int) It's the server's fd
* @param head (list_res_t *) Linked list which contains commands and responses
* @param cmd (char *) The command that we want to put in the linked list
* @param msg The message that we write on the server
* @return list_res_t* return the linked list
*/
list_res_t *request_std(int sfd, list_res_t *head, char *cmd, char *msg)
{
	if (!add_list_cmd(head, cmd) || dprintf(sfd, "%s\n", msg) == -1)
		return (NULL);
	return (head);
}

/**
* @brief Send a call to player of the same team for ritual
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return the linked list
*/
list_res_t *request_broadcast_call(client_t *self, list_res_t *head)
{
	if (!add_list_cmd(head, "Broadcast") ||
	dprintf(self->sfd, "Broadcast .%s 1 %d, %d %d\n", self->team,
		self->id, self->level,
		players_needed_by_ritual(self->level)) == -1) {
		return (NULL);
	}
	return (head);
}

/**
* @brief Communication broadcast to interact with other player
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param action (int) Action's index
* @return list_res_t* return a linked list
*/
list_res_t *request_broadcast(client_t *self, list_res_t *head, int action)
{
	if (!add_list_cmd(head, "Broadcast") ||
	dprintf(self->sfd, "Broadcast .%s %d %d\n",
	self->team, action, self->id) == -1)
		return (NULL);
	return (head);
}
