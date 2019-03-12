/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** handle_epoll_event
*/

#include "server.h"

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

static int	manage_event(server_t *serv, const int it
				, struct epoll_event *events)
{
	char buff[24];
	if (check_event(events, it) == ERR)
		return (ERR);
	if (serv->server_fd == events[it].data.fd) {
		printf("new connectkion from: %d\n", events[it].data.fd);
		if (handle_new_connection(serv) == ERR)
			return (ERR);
	} else {
		if (receve_msg() == ERR)
			return (ERR);
	}
	return (SUCCESS_RET);
}

int	handle_epoll_event(struct epoll_event *events, server_t *serv)
{
	int	ret = 0;

	for (int it = 0 ; it < serv->event_count ; it++) {
		ret = manage_event(serv, it, events);
		if (ret == ERR)
			continue ;
		else if (ret == ERR)
			return (ERR);
	}
	return (SUCCESS_RET);
}