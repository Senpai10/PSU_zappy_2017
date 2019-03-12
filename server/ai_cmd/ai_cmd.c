/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** ai_cmd
*/

#include "server.h"

static int	check(char **cmd, team_t *tmp, int new_fd, server_t *s)
{
	t_character	*ch = malloc(sizeof(*ch));
	if (ch == NULL)
		return (ERR);
	if (strcmp(cmd[0], tmp->name) == SUCCESS_RET) {
		if (tmp->nb_client > 0) {
			tmp->nb_client -= 1;
			dprintf(new_fd, "%d\n", tmp->nb_client);
			dprintf(new_fd, "%d %d\n", s->args->width
			, s->args->height);
			init_character(ch, tmp->name, new_fd, s);
			init_char_map(ch, s->root);
			if (s->g_clt != NULL)
				dprintf(s->g_clt->fd, "pnw %d %d %d %d %d %s\n"
			, new_fd, ch->x, ch->y, ch->angle, 1, ch->team);
			add_client_in_list(s->teams, new_fd, cmd[0]);
			return (SUCCESS_RET);
		}
	}
	return (ERR);
}

static int	check_new_team_name(char **cmd, server_t *serv, int new_fd)
{
	team_t	*tmp = serv->teams;
	fptr	ptr;

	while (tmp != NULL) {
		if (check(cmd, tmp, new_fd, serv) == SUCCESS_RET)
			return (2);
		tmp = tmp->next;
	}
	ptr = get_the_right_fnct(cmd[0]);
	if (ptr == NULL) {
		dprintf(new_fd, "ko\n");
		return (SUCCESS_RET);
	}
	add_cmd_to_list(serv, ptr, new_fd);
	return (SUCCESS_RET);
}

int	ai_cmd(char **cmd, server_t *serv, int new_fd)
{
	if (check_new_team_name(cmd, serv, new_fd) == 2)
		return (SUCCESS_RET);
	return (SUCCESS_RET);
}