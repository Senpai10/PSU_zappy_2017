/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check_error for client - zappy
*/

#include "client.h"

/**
* @brief check if the passed string is only composed of numbers
*
* i (int) iterator
* @param port string to check
* @return int return 84 in case of error
*/
int check_port(char *port)
{
	int i = 0;

	while (port[i] != '\0') {
		if (port[i] < '0' || port[i] > '9')
			return (84);
		i += 1;
	}
	return (0);
}

/**
* @brief check the presence of flags in the arguments
*
* @param argc (int) contain number of arguments entered
* @param argv (char **) contain the arguments
* @return int return 84 in case of error
*/
int check_flags(int argc, char **argv)
{
	if (strcmp(argv[1], "-p") != 0 || strcmp(argv[3], "-n") != 0)
		return (84);
	if (argc == 7 && strcmp(argv[5], "-h") != 0)
		return (84);
	return (0);
}

/**
* @brief check validity of arguments and call other checks functions
*
* @param argc (int) contain number of arguments entered
* @param argv (char **) contain the arguments
* @return int return 84 in case of error
*/
int check_error(int argc, char **argv)
{
	if ((argc != 5 && argc != 7) || check_flags(argc, argv) == 84
	|| check_port(argv[2]) == 84 || atoi(argv[2]) > 65535) {
		fprintf(stderr, "USAGE: ./zappy_ai -p port -n name -h ");
		fprintf(stderr, "machine\n");
		fprintf(stderr, "\tport is the port number\n");
		fprintf(stderr, "\tname is the name of the team\n");
		fprintf(stderr, "\tmachine is the name of the machine; ");
		fprintf(stderr, "localhost by default\n");
		return (84);
	}
	return (0);
}