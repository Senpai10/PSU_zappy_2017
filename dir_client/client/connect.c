/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** connection related functions
*/

#include "client.h"

/**
* @brief Create a socket object
* pe (struct protoent *) struct used by socket function to use TCP
*
* @return int containing the fd of the newly created socked
*/
int create_socket(void)
{
	struct protoent *pe = getprotobyname("TCP");

	if (!pe)
		return (-1);
	return (socket(AF_INET, SOCK_STREAM, pe->p_proto));
}

/**
* @brief bind the client and allow connection with server
* s_in (struct sockaddr_in) contain informations as port and host
*
* @param cmd (char **) contain the host and the port to connect with
* @param fd (int) file descriptor of the socket to associate with the connect
* @return int containing the fd of the socket or -1 in case of error
*/
int client_binding(char *host, char *port, int sfd)
{
	struct sockaddr_in s_in;
	struct hostent *pHostInfo;

	pHostInfo = gethostbyname(host);
	if(!pHostInfo) {
		close(sfd);
		return (-1);
	}
	s_in.sin_family = AF_INET;
	s_in.sin_addr.s_addr = inet_addr(inet_ntoa
				(*(struct in_addr *)pHostInfo->h_addr));
	s_in.sin_port = htons(atoi(port));
	if (connect(sfd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		close(sfd);
		return (-1);
	}
	return (sfd);
}

/**
* @brief Allows the client to connect to the server
*
* @param host (char *) the host
* @param port (int) the port
* @param self (client_t *) The struct which contains several information about
* IA
* @return true If there are no problem
* @return false If there are a problem
*/
bool connect_to_server(char *host, char *port, client_t *self)
{
	int sfd = create_socket();

	if (sfd == -1) {
		fprintf(stderr, "Error: cannot create the socket.\n");
		return (false);
	}
	if (client_binding(host, port, sfd) == -1) {
		fprintf(stderr, "Error: cannot connect to server.\n");
		return (false);
	}
	self->events = init_epoll(sfd, &(self->efd));
	if (!self->events) {
		if (self->efd != -1)
			close(self->efd);
		fprintf(stderr, "Error: failed to init epoll.\n");
		close(sfd);
		return (false);
	}
	self->sfd = sfd;
	return (true);
}
