/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** looking
*/

#include "server.h"

void	sd_vision_l(t_character *charac, t_tile *tile)
{
	int side_vision = 0;

	while (side_vision < charac->level) {
		describe_tile(charac, tile);
		if (tile->left != NULL)
			tile = tile->left;
		if (tile == NULL)
			return;
		side_vision++;
	}
}

void	sd_vision_r(t_character *charac, t_tile *tile)
{
	int side_vision = 0;

	while (side_vision < charac->level) {
		if (tile->right != NULL)
			tile = tile->right;
		if (tile == NULL)
			return;
		side_vision++;
	}
	while (side_vision > 0) {
		describe_tile(charac, tile);
		if (tile->left != NULL)
			tile = tile->left;
		if (tile == NULL)
			return;
		side_vision--;
	}
}

void	sd_vision_u(t_character *charac, t_tile *tile)
{
	int side_vision = 0;

	while (side_vision < charac->level) {
		if (tile->up != NULL)
			tile = tile->up;
		if (tile == NULL)
			return;
		side_vision++;
	}
	while (side_vision > 0) {
		describe_tile(charac, tile);
		if (tile->down != NULL)
			tile = tile->down;
		if (tile == NULL)
			return;
		side_vision--;
	}
}

void	look_right(t_character *charac, t_tile *tile)
{
	int	vision = 0;
	t_tile	*tmp;

	while (vision <= charac->level)
		{
			if (tile->right != NULL)
				tile = tile->right;
			if (tile == NULL)
				return;
			tmp = tile;
			sd_vision_u(charac, tile);
			tile = tmp;
			describe_tile(charac, tile);
			sd_vision_d(charac, tile);
			tile = tmp;
			vision++;
		}
}

void	look_down(t_character *charac, t_tile *tile)
{
	int	vision = 0;
	t_tile	*tmp;

	while (vision <= charac->level)
		{
			if (tile->down != NULL)
				tile = tile->down;
			if (tile == NULL)
				return;
			tmp = tile;
			sd_vision_r(charac, tile);
			tile = tmp;
			describe_tile(charac, tile);
			sd_vision_l(charac, tile);
			tile = tmp;
			vision++;
		}
}