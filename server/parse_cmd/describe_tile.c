/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** describe_tile
*/

#include "server.h"

int	print_attribute(t_character *charac, int nbr, char *attr, int r)
{
	int cpt = 0;

	while (cpt < nbr)
		{
			if (r == 0)
				dprintf(charac->fd, "%s", attr);
			else
				dprintf(charac->fd, " %s", attr);
			r = 1;
			cpt++;
		}
	return (r);
}

int	print_player(t_character *charac, t_tile *tile)
{
	int	i = 0;

	while (tile->first != NULL)
	{
		if (i == 0) {
			dprintf(charac->fd, "player");
			i = 1;
		}
		else
			dprintf(charac->fd, " player");
		tile->first = tile->first->next;
	}
	return (i);
}

void	describe_tile(t_character *charac, t_tile *tile)
{
	int	count = 0;

	count = print_player(charac, tile);
	count = print_attribute(charac, tile->deraumere, "deraumere", count);
	count = print_attribute(charac, tile->linemate, "linemate", count);
	count = print_attribute(charac, tile->sibur, "sibur", count);
	count = print_attribute(charac, tile->mendiane, "mendiane", count);
	count = print_attribute(charac, tile->phiras, "phiras", count);
	count = print_attribute(charac, tile->thystame, "thystame", count);
	count = print_attribute(charac, tile->food, "food", count);
	dprintf(charac->fd, ",");
}

void	side_vision_left(t_character *charac, t_tile *tile)
{
	int side_vision = 0;

	while (side_vision < charac->level) {
		if (tile->left != NULL)
			tile = tile->left;
		if (tile == NULL)
			return;
		side_vision++;
	}
	while (side_vision > 0) {
		describe_tile(charac, tile);
		if (tile->right != NULL)
			tile = tile->right;
		if (tile == NULL)
			return;
		side_vision--;
	}
}