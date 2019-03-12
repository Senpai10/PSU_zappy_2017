/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** handle_new_connection
*/

#include "server.h"

static int	get_epoll_events(struct epoll_event *event, const int serv_fd)
{
	memset(event, 0, sizeof(*event));
	if (serv_fd == ERR)
		return (ERR);
	event->events = EPOLLIN;
	event->data.fd = serv_fd;
	return (SUCCESS_RET);
}

/**
* \brief Create a new fd when a client wants to connect.
*
* \param serv A pointer to the server structure
* \return int Return the new client fd.
*/
int	handle_new_connection(server_t *serv)
{
	struct epoll_event event;
	struct sockaddr	in_addr;
	socklen_t	in_len = sizeof(in_addr);
	int		client_fd;

	client_fd = accept(serv->server_fd, &in_addr, &in_len);
	get_epoll_events(&event, client_fd);
	if (client_fd == ERR)
		return (ERR);
	if (epoll_ctl(serv->epoll_fd, EPOLL_CTL_ADD, client_fd, &event) == ERR)
		return (ERR);
	dprintf(client_fd, "WELCOME\n");
	return (client_fd);
}