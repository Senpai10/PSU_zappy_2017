/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** ai_cmd
*/

#include "server.h"

static int	check(char **cmd, team_t *tmp, int new_fd, server_t *serv)
{
	t_character	*charact = malloc(sizeof(*charact));
	if (charact == NULL)
		return (ERR);
	if (strcmp(cmd[0], tmp->name) == SUCCESS_RET) {
		if (tmp->nb_client > 0) {
			dprintf(new_fd, "%d\n", tmp->nb_client);
			dprintf(new_fd, "%d %d\n", serv->args->width
			, serv->args->height);
			tmp->nb_client -= 1;
			init_character(charact, tmp->name, new_fd);
			init_char_map(charact, serv->root);
			return (SUCCESS_RET);
		}
	}
	return (ERR);
}

static int	check_new_team_name(char **cmd, server_t *serv, int new_fd)
{
	team_t	*tmp = serv->teams;

	while (tmp != NULL) {
		if (check(cmd, tmp, new_fd, serv) == SUCCESS_RET) {
			return (2);
		}
		tmp = tmp->next;
	}
	dprintf(new_fd, "ko\n");
	return (SUCCESS_RET);
}

int	add_cmd(server_t *serv, char **cmd)
{
	struct timeval	time_begin;
	cmd_t	*new = malloc(sizeof(*new));

	gettimeofday(&time_begin, NULL);
	new->cmd = strdup(cmd[0]);
	new->time_begin = time_begin.tv_sec;
	serv->cmd = new;
	return (SUCCESS_RET);
}

int	ai_cmd(char **cmd, server_t *serv, int new_fd)
{
	if (check_new_team_name(cmd, serv, new_fd) == 2)
		return (SUCCESS_RET);
	add_cmd(serv, cmd);
	return (SUCCESS_RET);
}