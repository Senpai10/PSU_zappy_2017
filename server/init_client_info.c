/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_client_info
*/

#include "server.h"

server_t	*init_client_info(args_t *option)
{
	server_t	*info = malloc(sizeof(server_t));

	if (info == NULL)
		return (NULL);
	info->server_fd = get_client_fd(option->port, option);
	info->epoll_fd = create_epoll_instance(info->server_fd);
	if (info->server_fd == ERR || info->epoll_fd == ERR)
		return (NULL);
	info->teams = option->teams;
	return (info);
}