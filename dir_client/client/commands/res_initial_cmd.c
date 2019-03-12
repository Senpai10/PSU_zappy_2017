/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** team_res
*/

#include "client.h"

/**
* @brief Allows to retrieve the response of team_num
* (one of the first command)
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* containing the head or null if an error occurs
*/
list_res_t *team_initial_res(client_t *self, list_res_t *head)
{
	if (!request_std(self->sfd, head, "Team_num", self->team))
		return (NULL);
	return (head);
}

/**
* @brief Retrieve the response of team_map if team_num was okay
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* containing the head or null if an error occurs
*/
list_res_t *team_num_res(client_t *self, list_res_t *head)
{
	(void)self;
	if (!strcmp(head->res, "ko"))
		return (NULL);
	else if (!add_list_cmd(head, "Team_map"))
		return (NULL);
	return (head);
}

/**
* @brief Put Look in the queue when the first commands are okay
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return the linked list with new command
*/
list_res_t *team_map_res(client_t *self, list_res_t *head)
{
	if (!request_cmd(self->sfd, head, "Look"))
		return (NULL);
	return (head);
}
