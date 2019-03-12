/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_client_info
*/

#include "server.h"

/**
* \brief The teams structure with the max client per team.
*
* \param serv A pointer to the server structure.
* \return int Return sucess.
*/
static int	get_max_client(server_t *serv)
{
	team_t *team = serv->args->teams;

	while (team != NULL) {
		team->nb_client = serv->args->client_max;
		team = team->next;
	}
	return (SUCCESS_RET);
}

/**
* \brief Init the server structure.
*
* \param option A pointer to the args structure.
* \return server_t* A pointer to a server struct fill with the informations.
*/
server_t	*init_client_info(args_t *option)
{
	server_t	*info = malloc(sizeof(server_t));
	t_tile **map;

	if (info == NULL)
		return (NULL);
	info->server_fd = get_client_fd(option->port, option);
	info->epoll_fd = create_epoll_instance(info->server_fd);
	if (info->server_fd == ERR || info->epoll_fd == ERR)
		return (NULL);
	info->teams = option->teams;
	info->g_clt = NULL;
	info->args = option;
	get_max_client(info);
	map = init_map(info->args->width, info->args->height);
	map = init_ptr_lr(map, info->args->width, info->args->height);
	map = init_ptr_ud(map, info->args->width, info->args->height);
	info->root = &map[0][0];
	return (info);
}