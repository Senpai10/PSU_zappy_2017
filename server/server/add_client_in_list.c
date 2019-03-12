/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** add_client_in_list
*/

#include "server.h"

static int	fill_client(client_t *new, int client_fd)
{
	new->client_fd = client_fd;
	new->cmd = NULL;
	return (SUCCESS_RET);
}

static int	add_client_at_list(client_t *client, client_t *new)
{
	client_t	*tmp = client;

	while (tmp != NULL) {
		if (!tmp->next) {
			tmp->next = new;
			new->next = NULL;
			return (SUCCESS_RET);
		}
		tmp = tmp->next;
	}
	return (SUCCESS_RET);
}

int	add(team_t *team, int client_fd)
{
	client_t	*tmp = malloc(sizeof(client_t));

	if (!tmp)
		return (ERR);
	if (!team->client) {
		team->client = tmp;
		team->client->next = NULL;
	} else
		add_client_at_list(team->client, tmp);
	if (fill_client(tmp, client_fd) == ERR)
		return (ERR);
	return (SUCCESS_RET);
}

int	add_client_in_list(team_t *team, int client_fd, char *team_name)
{
	team_t		*team_tmp = team;

	while (team_tmp != NULL) {
		if (strcmp(team_name, team_tmp->name) == SUCCESS_RET) {
			add(team_tmp, client_fd);
			return (SUCCESS_RET);
		}
		team_tmp = team_tmp->next;
	}
	return (SUCCESS_RET);
}