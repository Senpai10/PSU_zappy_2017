/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** error_managment
*/

#include "server.h"

/**
* \brief Init the content of the args structure.
*
* \return args_t* A pointer to the new args structure.
*/
static args_t	*init_struct_option(void)
{
	args_t	*option = malloc(sizeof(args_t));

	if (option == NULL)
		return (NULL);
	option->port = 0;
	option->width = 0;
	option->height = 0;
	option->client_max = 0;
	option->freq = 100;
	option->teams = NULL;
	return (option);
}

/**
* \brief Manage the parameters.
*
* \param ac The number of arguments.
* \param av An array of the arguments.
* \return args_t* A pointer to the new args structure.
*/
args_t	*error_managment(int ac, char **av)
{
	args_t	*args = init_struct_option();

	if (ac < 14)
		return (NULL);
	if (args == NULL)
		return (NULL);
	if (get_args(ac, av, args) == ERR)
		return (NULL);
	return (args);
}