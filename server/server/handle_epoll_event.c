/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** handle_epoll_event
*/

#include "server.h"

/**
* \brief Check if the event is a error.
*
* \param events The array of event in the epoll isntance.
* \param it The index in the event array
* \return int Sucess or Error
*/
static int	check_event(struct epoll_event *events, const int it)
{
	if ((events[it].events & EPOLLERR)
	|| (events[it].events & EPOLLHUP)
	|| (!(events[it].events & EPOLLIN))) {
		fprintf(stderr, "epoll error\n");
		close(events[it].data.fd);
		return (ERR);
	}
	return (SUCCESS_RET);
}

/**
* \brief Check if a new connection or if a msg is receve.
*
* \param serv A pointer to the server structure
* \param it The index in the event array
* \param events The array of event in the epoll isntance.
* \return int Sucess or Error
*/
static int	manage_event(server_t *serv, const int it
				, struct epoll_event *events)
{
	if (check_event(events, it) == ERR)
		return (2);
	if (serv->server_fd == events[it].data.fd) {
		if (handle_new_connection(serv) == ERR)
			return (ERR);
	} else {
		if (receve_msg(events[it].data.fd, serv) == ERR)
			return (ERR);
	}
	return (SUCCESS_RET);
}

/**
* \brief Loop on the event get by epoll_wait.
*
* \param events The array of event in the epoll isntance.
* \param serv A pointer to the server structure.
* \return int Sucess or Error
*/
int	handle_epoll_event(struct epoll_event *events, server_t *serv)
{
	int	ret = 0;
	for (int it = 0 ; it < serv->event_count ; it++) {
		ret = manage_event(serv, it, events);
		if (ret == 2)
			continue ;
		else if (ret == ERR)
			return (ERR);
	}
	return (SUCCESS_RET);
}