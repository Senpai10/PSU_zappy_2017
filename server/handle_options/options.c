/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** p_option
*/

#include "server.h"

/**
* \brief The P parameter.
*
* \param option A pointer to the args structure.
* \param it The it of the arguments.
* \param av The array of arguments.
* \param ac The number of arguments.
* \return int
*/
int	p_option(args_t *option, int *it, char **av, int ac)
{
	(*it)++;
	if (av[(*it)] != NULL)
		option->port = atoi(av[(*it)]);
	else {
		fprintf(stderr, "Invalid port option\n");
		return (ERR);
	}
	(void)ac;
	return (SUCCESS_RET);
}

/**
* \brief The x parameter.
*
* \param option A pointer to the args structure.
* \param it The it of the arguments.
* \param av The array of arguments.
* \param ac The number of arguments.
* \return int
*/
int	x_option(args_t *option, int *it, char **av, int ac)
{
	(*it)++;
	if (av[(*it)] != NULL)
		option->width = atoi(av[(*it)]);
	else {
		fprintf(stderr, "Invalid width option\n");
		return (ERR);
	}
	(void)ac;
	return (SUCCESS_RET);
}

/**
* \brief The y parameter.
*
* \param option A pointer to the args structure.
* \param it The it of the arguments.
* \param av The array of arguments.
* \param ac The number of arguments.
* \return int
*/
int	y_option(args_t *option, int *it, char **av, int ac)
{
	(*it)++;
	if (av[(*it)] != NULL)
		option->height = atoi(av[(*it)]);
	else {
		fprintf(stderr, "Invalid height option\n");
		return (ERR);
	}
	(void)ac;
	return (SUCCESS_RET);
}

/**
* \brief The f parameter.
*
* \param option A pointer to the args structure.
* \param it The it of the arguments.
* \param av The array of arguments.
* \param ac The number of arguments.
* \return int
*/
int	f_option(args_t *option, int *it, char **av, int ac)
{
	(*it)++;
	if (av[(*it)] != NULL)
		option->freq = atoi(av[(*it)]);
	else {
		fprintf(stderr, "Invalid frequence option\n");
		return (ERR);
	}
	(void)ac;
	return (SUCCESS_RET);
}

/**
* \brief The c parameter.
*
* \param option A pointer to the args structure.
* \param it The it of the arguments.
* \param av The array of arguments.
* \param ac The number of arguments.
* \return int
*/
int	c_option(args_t *option, int *it, char **av, int ac)
{
	(*it)++;
	if (av[(*it)] != NULL)
		option->client_max = atoi(av[(*it)]);
	else {
		fprintf(stderr, "Invalid team_max option\n");
		return (ERR);
	}
	(void)ac;
	return (SUCCESS_RET);
}