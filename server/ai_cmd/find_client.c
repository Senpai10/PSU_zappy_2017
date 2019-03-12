/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** find_client
*/

#include "server.h"

static int	find_fd(client_t *clt, int client_fd)
{
	client_t	*tmp = clt;

	while (tmp != NULL) {
		if (clt->client_fd == client_fd) {
			return (SUCCESS_RET);
		}
		tmp = tmp->next;
	}
	return (ERR);
}

client_t	*get_client(team_t *team, int client_fd)
{
	team_t		*tmp_team = team;
	client_t	*tmp_clt;

	while (tmp_team != NULL) {
		tmp_clt = tmp_team->client;
		if (find_fd(tmp_clt, client_fd) == SUCCESS_RET) {
			return (tmp_clt);
		}
		tmp_team = tmp_team->next;
	}
	return (NULL);
}
