/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get_arguments
*/

#include "server.h"

static char	*option[7] = {"-c", "-x", "-h", "-p", "-f", "-n", NULL};

static func_t tab[7] = {
	&c_option
	, &x_option
	, &y_option
	, &p_option
	, &f_option
	, &n_option
	, NULL
};

/**
* \brief Check the arguments and call an array of pointer.
*
* \param ac The number os arguments.
* \param av The array of arguments.
* \param args A pointer to the args structure.
* \param it A pointer to the it of array.
* \return int Return sucess of error.
*/
static int	check_args(const int ac, char **av, args_t *args, int *it)
{
	int	x = 0;

	while (option[x] && strcmp(option[x], av[(*it)]) != 0)
		x++;
	if (option[x] != NULL) {
		if (tab[x](args, it, av, ac) == ERR)
			return (ERR);
	} else {
		fprintf(stderr, "Invalid option\n");
		return (ERR);
	}
	return (SUCCESS_RET);
}

/**
* \brief Get the args object
*
* \param ac The number of arguments.
* \param av The array of arguments.
* \param args A pointer to the args structure.
* \return int Return sucess or return.
*/
int	get_args(int ac, char **av, args_t *args)
{
	int	x = 1;

	while (x < ac) {
		if (check_args(ac, av, args, &x) == ERR)
			return (ERR);
		x++;
	}
	return (SUCCESS_RET);
}