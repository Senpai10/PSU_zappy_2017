/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** option
*/

#ifndef OPTION_H_
	#define OPTION_H_

#include "server.h"

typedef struct	team_s
{
	char	*name;
	int	nb_client;
	struct client_s	*client;
	struct team_s	*next;
}		team_t;

typedef struct	args_s
{
	struct team_s	*teams;
	int	port;
	int	width;
	int	height;
	int	client_max;
	int	freq;
}		args_t;

int	n_option(args_t *option, int *it, char **av, int ac);
int	y_option(args_t *option, int *it, char **av, int ac);
int	x_option(args_t *option, int *it, char **av, int ac);
int	f_option(args_t *option, int *it, char **av, int ac);
int	c_option(args_t *option, int *it, char **av, int ac);
int	p_option(args_t *option, int *it, char **av, int ac);
int	add_new_team(args_t *serv, char *name);
int	check_option(args_t *args);

typedef int (*func_t)(args_t *option, int *it, char **av, int ac);

#endif
