/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** turn_command
*/

#include "server.h"

void	side_vision_right(t_character *charac, t_tile *tile)
{
	int side_vision = 0;

	while (side_vision < charac->level) {
		describe_tile(charac, tile);
		if (tile->right != NULL)
			tile = tile->right;
		if (tile == NULL)
			return;
		side_vision++;
	}
}

void	look_up(t_character *charac, t_tile *tile)
{
	int	vision = 0;
	t_tile	*tmp;

	while (vision <= charac->level)
		{
			if (tile->up != NULL)
				tile = tile->up;
			if (tile == NULL)
				return;
			tmp = tile;
			side_vision_left(charac, tile);
			tile = tmp;
			describe_tile(charac, tile);
			side_vision_right(charac, tile);
			tile = tmp;
			vision++;
		}
}

void	m_look(t_character *charac, t_tile *tile, server_t *serv)
{
	(void)serv;
	if (charac == NULL)
		return ;
	dprintf(charac->fd, "[");
	describe_tile(charac, tile);
	dprintf(charac->fd, ",");
	if (charac->angle == 1)
		look_up(charac, tile);
	else if (charac->angle == 2)
		look_right(charac, tile);
	else if (charac->angle == 3)
		look_down(charac, tile);
	else
		look_left(charac, tile);
	dprintf(charac->fd, "]");
}

void	m_left(t_character *charac, t_tile *tile, server_t *serv)
{
	(void)serv;
	(void)tile;
	if (charac == NULL)
		return ;
	if (charac->angle == 1)
		charac->angle = 4;
	else
		charac->angle = charac->angle - 1;
	dprintf(charac->fd, "ok\n");
}

void	m_right(t_character *charac, t_tile *tile, server_t *serv)
{
	(void)serv;
	(void)tile;
	if (charac == NULL)
		return ;
	if (charac->angle == 4)
		charac->angle = 1;
	else
		charac->angle = charac->angle + 1;
	dprintf(charac->fd, "ok\n");
}
