/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** add_cmd
*/

#include "server.h"

void	m_look(t_character *charac, t_tile *tile, server_t *serv);
void	m_right(t_character *charac, t_tile *tile, server_t *serv);
void	m_left(t_character *charac, t_tile *tile, server_t *serv);
void	m_forward(t_character *charac, t_tile *tile, server_t *serv);

int	get_the_index(char *str)
{
	char **tab;
	int	i = 0;

	tab = malloc(sizeof(char *) * 5);
	if (tab == NULL)
		exit(84);
	tab[0] = strdup("Forward");
	tab[1] = strdup("Right");
	tab[2] = strdup("Left");
	tab[3] = strdup("Look");
	tab[4] = NULL;
	while (tab[i] != NULL) {
		if (strcmp(tab[i], str) == SUCCESS_RET)
			return (i);
		i++;
	}
	return (i);
}

fptr	get_the_right_fnct(char *str)
{
	fptr		p[4];
	int		i = 0;

	p[0] = &m_forward;
	p[1] = &m_right;
	p[2] = &m_left;
	p[3] = &m_look;
	i = get_the_index(str);
	if (i > 3)
		return (NULL);
	return (p[i]);
}

static int	fill_cmd(cmd_t *new, fptr ptr, int freq)
{
	long	time;
	struct timeval	time_actual;

	gettimeofday(&time_actual, NULL);
	time = time_actual.tv_sec;
	new->initialize = 0;
	new->time_cmd = 7 / freq;
	new->time_begin = time;
	new->i = ptr;
	return (SUCCESS_RET);
}

static int	add_cmd_at_list(cmd_t *cmd, cmd_t *new)
{
	cmd_t *tmp = cmd;

	while (tmp != NULL) {
		if (!tmp->next) {
			tmp->next = new;
			cmd->next = NULL;
			return (SUCCESS_RET);
		}
		tmp = tmp->next;
	}
	return (SUCCESS_RET);
}

int	add_cmd_to_list(server_t *serv, fptr ptr, int client_fd)
{
	client_t	*clt = get_client(serv->teams, client_fd);
	cmd_t		*tmp = malloc(sizeof(cmd_t));

	if (list_len(clt) > 10)
		return (SUCCESS_RET);
	if (!tmp)
		return (ERR);
	if (!clt->cmd) {
		tmp->next = NULL;
		clt->cmd = tmp;
		clt->cmd->next = NULL;
	} else
		add_cmd_at_list(clt->cmd, tmp);
	fill_cmd(tmp, ptr, serv->args->freq);
	return (SUCCESS_RET);
}