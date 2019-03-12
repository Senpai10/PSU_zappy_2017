/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** n_option
*/

#include "server.h"

/**
* \brief Check the end of the n flags
*
* \param it A pointer to the it of the arguments.
* \param av The array of arguments.
* \return int Return sucess or error.
*/
static int	end_n_option(int *it, char **av)
{
	if (av[(*it)] == NULL || av[(*it)][0] == '-') {
		(*it)--;
		return (SUCCESS_RET);
	}
	return (ERR);
}

/**
* \brief Handle the flag n.
*
* \param option A pointer to the option parameter.
* \param it The it of the arguments.
* \param av The array of arguments.
* \param ac the number of aguments.
* \return int Return sucess or error.
*/
int	n_option(args_t *option, int *it, char **av, int ac)
{
	(*it)++;
	while ((*it) != ac) {
		if (end_n_option(it, av) == SUCCESS_RET)
			break ;
		if (add_new_team(option, av[(*it)]) == ERR)
			return (ERR);
		(*it)++;
	}
	return (SUCCESS_RET);
}
