/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** moving_command
*/

#include "server.h"

int	moove_up(t_character *charac, t_tile *tile)
{
	if (tile->up == NULL) {
		return (1);
	}
	else {
		charac->y = charac->y - 1;
		chaining_char(tile->up, charac);
	}
	return (0);
}

int	moove_down(t_character *charac, t_tile *tile)
{
	if (tile->down == NULL) {
		return (1);
	}
	else {
		charac->y = charac->y + 1;
		chaining_char(tile->down, charac);
	}
	return (0);
}

int	moove_right(t_character *charac, t_tile *tile)
{
	if (tile->right == NULL) {
		return (1);
	}
	else{
		charac->x = charac->x + 1;
		chaining_char(tile->right, charac);
	}
	return (0);
}

int	moove_left(t_character *charac, t_tile *tile)
{
	if (tile->left == NULL)
		return (1);
	else {
		charac->x = charac->x - 1;
		chaining_char(tile->left, charac);
	}
	return (0);
}

void	m_forward(t_character *charac, t_tile *tile, server_t *serv)
{
	if (charac == NULL)
		return ;
	int x = charac->x;
	int y = charac->y;
	int i = 0;
	if (charac->angle == 1)
		i = moove_up(charac, tile);
	if (charac->angle == 2)
		i = moove_right(charac, tile);
	if (charac->angle == 3)
		i = moove_down(charac, tile);
	if (charac->angle == 4)
		i = moove_left(charac, tile);
	if (i == 0)
		remooving_char(serv->root, x, y);
	dprintf(charac->fd, "ok\n");
	dprintf(serv->g_clt->fd, "ppo %d %d %d %d %d %s\n", charac->fd
		, charac->x, charac->y, charac->angle, charac->level
		, charac->team);
}