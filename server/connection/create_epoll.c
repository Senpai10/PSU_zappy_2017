/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create_epoll
*/

#include "server.h"
/**
* \brief Fill the struct event with the new fd
*
* \param event The struct to fill
* \param serv_fd The new fd create by socket
* \return int Retrun sucess or error
*/
int	get_epoll_event(struct epoll_event *event, const int serv_fd)
{
	memset(event, 0, sizeof(*event));
	if (serv_fd == ERR)
		return (ERR);
	event->events = EPOLLIN | EPOLLOUT;
	event->data.fd = serv_fd;
	return (SUCCESS_RET);
}

/**
* \brief Create a epoll instance object
*
* \param serv_fd The fd create by socket
* \return int The epoll instance
*/
int	create_epoll_instance(const int serv_fd)
{
	int epoll_fd = epoll_create1(0);
	struct epoll_event event;

	get_epoll_event(&event, serv_fd);
	if (epoll_fd == -ERR)
		return (ERR);
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, serv_fd, &event))
		return (ERR);
	return (epoll_fd);
}