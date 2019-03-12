/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server
*/

#include "server.h"

const int SUCCESS_RET = 0;
const int ERR_RET = 84;
const int ERR = -1;

int	main(int ac, char **av)
{
	args_t		*option = error_managment(ac, av);
	server_t	*server;

	if (option == NULL) {
		print_usage();
		return (ERR_RET);
	}
	server = init_client_info(option);
	if (server == NULL)
		return (ERR_RET);
	if (server_loop(server) == ERR)
		return (ERR_RET);
	return (0);
}