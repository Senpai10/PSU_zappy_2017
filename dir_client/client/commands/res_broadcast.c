/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** functions for broadcast responses handling
*/

#include "client.h"

/**
* @brief Resolve the response of broadcast
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* containing the head or null if an error occurs
*/
list_res_t *broadcast_res(client_t *self, list_res_t *head)
{
	if (self->role & r_caller &&
	!(self->role & r_present) && self->r_act == 0) {
		self->role += r_present;
		start_ritual(self, head);
	} else if (self->role & r_caller &&
	!(self->role & r_present) && self->r_act) {
		head = request_broadcast_call(self, head);
	}
	return (head);
}
