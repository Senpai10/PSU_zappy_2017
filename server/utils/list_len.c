/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** list_len
*/

#include "server.h"

int	list_len(client_t *clt)
{
	client_t	*tmp = clt;
	int		it = 0;

	while (tmp != NULL) {
		it++;
		tmp = tmp->next;
	}
	return (it);
}