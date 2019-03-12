/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get_client_fd
*/

#include "server.h"

/**
* \brief Create the socket witj "socket" fucntion
*
* \param port The port passed as parameter
* \return int The new fd create by socket
*/
static int init_port(const int port)
{
	struct protoent *pe;
	struct sockaddr_in s_in;
	int fd;

	pe = getprotobyname("TCP");
	if (!pe)
		return (ERR);
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == ERR)
		return (ERR);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -ERR)
		return (ERR);
	return (fd);
}

/**
* \brief Get the client fd object
*
* \param port The port passed as parameter
* \param args All of the argument
* \return int Return the new fd
*/
int	get_client_fd(const int port, args_t *args)
{
	int	serv_fd = init_port(port);

	if (serv_fd == ERR)
		return (ERR);
	if (listen(serv_fd, args->client_max) == ERR)
		return (ERR);
	return (serv_fd);
}