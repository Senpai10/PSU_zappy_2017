/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** time_handling
*/

#include "server.h"

static int	check_cmd_to_send(client_t *clt, server_t *serv)
{
	cmd_t		*cmd = clt->cmd;
	t_character 	*charact;
	t_tile		*tile;
	struct timeval	time_actual;
	long		time;

	gettimeofday(&time_actual, NULL);
	time = time_actual.tv_sec;
	charact = find_player_c(clt->client_fd, serv->root, serv);
	tile = find_player(clt->client_fd, serv->root, serv);
	while (time - cmd->time_begin < cmd->time_cmd) {
		gettimeofday(&time_actual, NULL);
		time = time_actual.tv_sec;
	}
	(*cmd->i)(charact, tile, serv);
	if (cmd->next == NULL)
		clt->cmd = NULL;
	else
		clt->cmd = clt->cmd->next;
	return (SUCCESS_RET);
}

static int	find_cmd_in_client(server_t *serv, team_t *team)
{
	client_t	*clt = team->client;

	while (clt != NULL) {
		if (clt->cmd != NULL)
			check_cmd_to_send(clt, serv);
		clt = clt->next;
	}
	return (SUCCESS_RET);
}

int	find_in_team(server_t *serv)
{
	team_t		*team = serv->teams;

	while (team != NULL) {
		if (team->client != NULL)
			find_cmd_in_client(serv, team);
		team = team->next;
	}
	return (SUCCESS_RET);
}