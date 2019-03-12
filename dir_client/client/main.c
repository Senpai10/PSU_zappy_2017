/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main for client - zappy
*/

#include "client.h"

int main(int ac, char **av)
{
	if (check_error(ac, av) == 84)
		return (84);
	if (!client_initialization((ac == 7) ? av[6] : "localhost",
							av[2], av[4]))
		return (84);
	return (0);
}