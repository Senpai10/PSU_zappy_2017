/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** init_ressources
*/

#include "server.h"

void	fill_tile(t_tile *tile)
{
	tile->linemate = rand() % 2;
	tile->deraumere = rand() % 2;
	tile->sibur = rand() % 2;
	tile->mendiane = rand() % 2;
	tile->phiras = rand() % 2;
	tile->thystame = rand() % 2;
	tile->food = rand() % 2;
}

void	init_tiles(t_tile **map, int x, int y)
{
	int 	xp = 0;
	int	yp = 0;

	srand(time(NULL));
	while (yp <= y)
	{
		while (xp <= x) {
			fill_tile(&map[yp][xp]);
			xp++;
		}
		yp++;
	}

}