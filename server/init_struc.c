/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_struc
*/

#include "server.h"

/**
* \brief Init the tile.
*
* \param tile A pointer to the tile.
*/
t_tile	init_tile(void)
{
	t_tile *tile;

	tile = malloc(sizeof(t_tile));
	tile->linemate = rand() % 10;
	tile->deraumere = rand() % 10;
	tile->sibur = rand() % 10;
	tile->mendiane = rand() % 10;
	tile->phiras = rand() % 10;
	tile->thystame = rand() % 10;
	tile->food = rand() % 10;
	tile->egg = 0;
	tile->elevation_ready = 0;
	tile->first = NULL;
	tile->right = NULL;
	tile->left = NULL;
	tile->up = NULL;
	tile->down = NULL;
	return (*tile);
}

/**
* \brief Init the when character when a connection spawn
*
* \param charac A pointer to the new charcacter
* \param team The name of the team
* \param fd The fd of the new client.
*/
void	init_character(t_character *charac, char *team, int fd
				, server_t *serv)
{
	charac->linemate = 0;
	charac->deraumere = 0;
	charac->sibur = 0;
	charac->mendiane = 0;
	charac->phiras = 0;
	charac->thystame = 0;
	charac->do_i_need_food = 0;
	charac->team = strdup(team);
	charac->x = rand() % (serv->args->width - 1);
	charac->y = rand() % (serv->args->height - 1);
	charac->angle = 1;
	charac->fd = fd;
	charac->next = NULL;
	charac->level = 0;
}

t_tile  **init_ptr_lr(t_tile  **map, int x, int y)
{
	int	xp = 0;
	int	yp = 0;
	while (yp < y) {
		while (xp < x) {
			if (xp == 0)
				map[yp][xp].left = NULL;
			else
				map[yp][xp].left = &map[yp][xp - 1];
			if (xp == x - 1)
				map[yp][xp].right = NULL;
			else
				map[yp][xp].right = &map[yp][xp + 1];
			xp++;
		}
		xp = 0;
		yp++;
	}
	return (map);
}

t_tile  **init_ptr_ud(t_tile **map, int x, int y)
{
	int	xp = 0;
	int	yp = 0;

	while (yp < y) {
		while (xp < x) {
			if (yp == 0)
				map[yp][xp].up = NULL;
			else
				map[yp][xp].up = &map[yp - 1][xp];
			if (yp == y - 1)
				map[yp][xp].down = NULL;
			else
				map[yp][xp].down = &map[yp + 1][xp];
			xp++;
		}
		xp = 0;
		yp++;
	}
	return (map);
}

t_tile	**init_map(int x, int y)
{
	t_tile	**map;
	int	xp = 0;
	int	yp = 0;

	map = malloc(sizeof(t_tile*) * y + 1);
	if (map == NULL)
		exit (84);
	while (yp < y)
	{
		map[yp] = malloc(sizeof(t_tile) * x);
		if (map[yp] == NULL)
			exit (84);
		while (xp < x) {
			map[yp][xp] = init_tile();
			xp++;
		}
		xp = 0;
		yp++;
	}
	return (map);
}