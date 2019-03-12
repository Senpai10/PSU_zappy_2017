/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** epoll related functions
*/

#include "client.h"

/**
* @brief function to add fd on the epoll events
* event (struct epoll_event) tmp struct to perform actions on efd
*
* @param efd (int) epoll fd on which events are performed
* @param fd (int) file descriptor to add to the events
* @return true if no problem as occured
* @return false if epoll_ctl failed to add fd
*/
bool add_fd_on_events(int efd, int fd)
{
	struct epoll_event event;

	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET;
	if (epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event) == -1) {
		fprintf(stderr, "Error on adding fd in events.\n");
		return (false);
	}
	return (true);
}

/**
* @brief function to delete fd on the epoll events
* event (struct epoll_event) tmp struct to perform actions on efd
*
* @param self (t_link *) contains epoll related informations such as efd
* @param fd (int) file descriptor to delete from the events
* @return true if no problem as occured
* @return false if epoll_ctl failed to delete fd
*/
bool del_fd_on_events(client_t *self, int fd)
{
	struct epoll_event event;

	if (epoll_ctl(self->efd, EPOLL_CTL_DEL, fd, &event) == -1) {
		fprintf(stderr, "Error on deleting fd in events.\n");
		return (false);
	}
	close(fd);
	self->sfd = -1;
	if (printf("Disconnected from server.\n") == -1)
		return (false);
	return (true);
}

/**
* @brief initialize a epoll events struct
*
* @param fd_s (int) filedescriptor associated with epoll creation
* @param efd (int *) epoll filedescriptor to store the epoll initialization
* @return struct epoll_event* contain the events
*/
struct epoll_event *init_epoll(int sfd, int *efd)
{
	struct epoll_event event;
	struct epoll_event *events;
	int s;

	*efd = epoll_create1(0);
	if (*efd == -1)
		return (NULL);
	memset(&event, 0, sizeof(event));
	event.data.fd = sfd;
	event.events = EPOLLIN | EPOLLET;
	s = epoll_ctl(*efd, EPOLL_CTL_ADD, sfd, &event);
	if (s == -1)
		return (NULL);
	events = calloc(64, sizeof(event));
	return (events);
}
