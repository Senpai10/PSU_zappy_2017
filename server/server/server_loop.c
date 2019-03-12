/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server_loop
*/

#include "server.h"

const int MAX_EVENTS = 64;
const int ALLOC_EVENTS = 15;

/**
* \brief Main loop of the server with a call of epoll_wait.
*
* \param info A pointer to the server structure
* \return int Return sucess or error.
*/
int	server_loop(server_t *info)
{
	struct	epoll_event *events;

	events = calloc(ALLOC_EVENTS, sizeof(events));
	while (1) {
		info->event_count = epoll_wait(info->epoll_fd
						, events, MAX_EVENTS, 50);
		if (info->event_count == ERR)
			return (ERR);
		if (handle_epoll_event(events, info) == ERR)
			return (ERR);
		find_in_team(info);
	}
	return (SUCCESS_RET);
}