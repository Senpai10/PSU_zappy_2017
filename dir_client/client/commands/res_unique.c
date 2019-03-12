/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** unique responses commands file
*/

#include "client.h"

/**
* @brief Response by default
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @return list_res_t* the linked list
*/
list_res_t *handle_ok_res(client_t *self, list_res_t *head)
{
	(void)self;
	(void)head;
	return (head);
}
