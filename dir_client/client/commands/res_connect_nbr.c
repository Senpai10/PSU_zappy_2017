/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fork
*/

#include "client.h"

/**
* @brief get the number of clients that can connect to the server
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* containing the head or null if an error occurs
*/
list_res_t *connect_nbr_res(client_t *self, list_res_t *head)
{
	int slot = atoi(head->res);

	if (slot <= 0) {
		if (!request_cmd(self->sfd, head, "Fork"))
			return (NULL);
	}
	if (!request_cmd(self->sfd, head, "Look"))
		return (NULL);
	return (head);
}