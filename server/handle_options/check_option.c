/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** check_option
*/

#include "server.h"

/**
* \brief Check the content of the args structure.
*
* \param args A pointer to the args structure.
* \return int Return sucess or error.
*/
static int	check_param(args_t * args)
{
	if (args->port < 1)
		return (ERR);
	if (args->width > 200)
		return (ERR);
	if (args->height > 200)
		return (ERR);
	if (args->client_max < 2)
		return (ERR);
	if (args->freq < 300)
		return (ERR);
	return (SUCCESS_RET);
}

/**
* \brief Check all the teaml name.
*
* \param team A pointer to he team structure.
* \return int Return sucess or error.
*/
static int	check_name_team(team_t *team)
{
	int	it = 0;

	for (team_t *tmp = team ; tmp != NULL ; tmp = tmp->next)
		it++;
	if (it == 1)
		return (ERR);
	return (SUCCESS_RET);
}

/**
* \brief Check the options passed as paramter.
*
* \param args A pointer to the args structure.
* \return int Return sucess or error.
*/
int	check_option(args_t *args)
{
	if (check_param(args) == ERR)
		return (ERR);
	if (check_name_team(args->teams) == ERR)
		return (ERR);
	return (SUCCESS_RET);
}