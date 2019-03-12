/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** map
*/

#ifndef MAP_H_
	#define MAP_H_

#include "server.h"

typedef struct	s_map
{
	int		pos_x;
	int		pos_y;
	struct s_map	*next;
}		map_t;

#endif
