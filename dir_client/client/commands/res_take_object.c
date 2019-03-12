/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** take object
*/

#include "client.h"

/**
* @brief Allows to take an object
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param object The object's name taken
* @return list_res_t* the linked list with the commands Take
*/
list_res_t *take_object(client_t *self, list_res_t *head, char *object)
{
	if (head == NULL)
		return (NULL);
	if (!add_list_cmd(head, "Take"))
		return (NULL);
	if (dprintf(self->sfd, "Take %s\n", object) == -1)
		return (NULL);
	return (head);
}

/**
* @brief According to the Take's response, launch the command Inventory for OK
* or Look for KO
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @return list_res_t* return the linked list with the command Inventory or Look
*/
list_res_t *take_object_res(client_t *self, list_res_t *head)
{
	if (strcmp("ok", head->res) == 0 && !(self->role & r_caller)) {
		if (!request_cmd(self->sfd, head, "Inventory"))
			return (NULL);
	} else if (!(self->role & r_caller) &&
		!request_cmd(self->sfd, head, "Look"))
		return (NULL);
	return (head);
}
