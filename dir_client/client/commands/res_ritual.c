/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** functions for ritual responses
*/

#include "client.h"

/**
* @brief Update his state when he evolve to search the stone needed to pass to
* the next level
*
* @param state (int) His current state
* @param level (int) His current level
* @return int return the new state
*/
static int update_state(int state, int level)
{
	int ns = (state & n_food) ? n_food : 0;

	switch (level) {
	case 1:
		return (ns += n_linemate);
	case 2:
		return (ns += n_linemate + n_deraumere + n_sibur);
	case 3:
		return (ns += n_linemate + n_sibur + n_phiras);
	case 4:
		return (ns += n_linemate + n_deraumere + n_sibur + n_phiras);
	case 5:
		return (ns += n_linemate + n_deraumere + n_sibur + n_mendiane);
	case 6:
		return (ns += n_linemate + n_deraumere + n_sibur + n_phiras);
	case 7:
		return (ns += n_linemate + n_deraumere + n_sibur +
		n_mendiane + n_phiras + n_thystame);
	}
	return (ns);
}

/**
* @brief At the end of the ritual, update his state and search for new stone
* to evolve
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @return list_res_t* return the linked list with new command and his state is
* updated for what he need to evolve to the next level
*/
list_res_t *ritual_res_end(client_t *self, list_res_t *head)
{
	self->role = 0;
	self->r_act = 0;
	if (strcmp("ko", head->res) != 0)
		self->level++;
	self->state = update_state(self->state, self->level);
	if (!request_cmd(self->sfd, head, "Connect_nbr"))
		return (NULL);
	return (head);
}

/**
* @brief Allows to retrieve the response 'Elevation underway'
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @return list_res_t* return the linked list
*/
list_res_t *ritual_res_active(client_t *self, list_res_t *head)
{
	(void)self;
	if (!add_list_cmd(head, "Ritual End"))
		return (NULL);
	return (head);
}
