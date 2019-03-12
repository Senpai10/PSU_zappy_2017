/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** print_usage
*/

#include "server.h"

void	print_usage(void)
{
	printf("USAGE: ./zappy_server -p port -x width -y height -n name1");
	printf(" name2 ... -c clientNb -f freq\n");
	printf("\tport\tis the port number\n");
	printf("\twidth\tis the width of the world\n");
	printf("\theight\tis the height of the world\n");
	printf("\tnameX\tis the name of the team X\n");
	printf("\tclientNb\tis the number of authorized clients per team\n");
	printf("\tfreq\tis the reciprocal of time unit for execution");
	printf(" of actions\n");
}