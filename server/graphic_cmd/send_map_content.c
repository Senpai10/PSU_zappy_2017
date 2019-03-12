/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** send_map_content
*/

#include "server.h"

/**
* \brief Sent player infomation to graphical client.
*
* \param player A pointer to linked list if character.
* \param client_fd The graphical client of fd?
* \return int Return sucess or error.
*/
static int	send_player(t_character *player, const int client_fd)
{
	t_character *tmp = player;

	while (tmp != NULL) {
		printf("envoie player\n");
		dprintf(client_fd, "pnw %d %d %d %d %d %s\n", client_fd
			, player->x, player->y, player->angle, 1
			, player->team);
		tmp = tmp->next;
	}
	return (SUCCESS_RET);
}

static int	print_bct(t_tile *root, server_t *serv, int x, int y)
{
	dprintf(serv->g_clt->fd
		, "bct %d %d %d %d %d %d %d %d %d\n", x, y, root->food
		, root->linemate, root->deraumere, root->sibur
		, root->mendiane, root->phiras, root->thystame);
	send_player(root->first, serv->g_clt->fd);
	return (SUCCESS_RET);
}
/**
* \brief Sent the content of the map to grpahical client.
*
* \param serv A pointer to server struture.
* \return int Return sucess or error.
*/
int	send_map_content(server_t *serv)
{
	t_tile	*tmp = serv->root;
	t_tile	*root = serv->root;
	int	x = 0;
	int	y = 0;

	while (y < serv->args->height) {
		while (x < serv->args->width) {
			print_bct(root, serv, x, y);
			root = root->right;
			x++;
		}
		x = 0;
		y++;
		root = tmp->down;
		tmp = tmp->down;
	}
	return (SUCCESS_RET);
}