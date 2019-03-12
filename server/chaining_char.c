/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** chaining_char
*/

#include "includes/server.h"

void	chaining_char(t_tile *tile, t_character *last)
{
	t_character *tmp = tile->first;

	if (tile->first == NULL)
	{
		tile->first = last;
		printf("MON CARAC EST A X:%d et Y:%d\n", tile->first->x, tile->first->y);
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
	printf("MON CARAC EST A X:%d et Y:%d\n", tile->first->x, tile->first->y);
}

void	init_char_map(t_character *charac, t_tile *root)
{
	int x = 0;
	int y = 0;
	t_tile	*tmp = root;
	while (x != charac->x)
	{
		tmp = tmp->right;
		x++;
	}
	while (y != charac->y)
	{
		tmp = tmp->down ;
		y++;
	}
	chaining_char(tmp, charac);
}

void	remooving_char(t_tile *root, int x, int y)
{
	int xp = 0;
	int yp = 0;
	t_tile *tmp = root;

	while (xp != x)
		{
			root = root->right;
			xp++;
		}
	while (yp != y)
		{
			root = root->down;
			yp++;
		}
	root->first = root->first->next;
	root = tmp;
}