/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** map_navigate
*/

#include "server.h"

int		is_player_here(int fd, t_tile *tile)
{
	while (tile->first != NULL)
		{
			if (tile->first->fd == fd)
				return (1);
			tile->first = tile->first->next;
		}
	return (-1);
}

t_tile		*find_player(int fd, t_tile *root, server_t *serv)
{
	t_tile *tmp = root;
	int x = 0;
	int y = 0;
	while (y != serv->args->height - 1) {
		while (x != serv->args->width - 1) {
			if (is_player_here(fd, root) != -1)
				return (root);
			root = root->right;
			x++;
		}
		x = 0;
		y++;
		root = tmp->down;
		tmp = tmp->down;
	}
	return (NULL);
}

t_character		*is_player_here_c(int fd, t_tile *tile)
{
	while (tile->first != NULL)
		{
			if (tile->first->fd == fd)
				return (tile->first);
			tile->first = tile->first->next;
		}
	return (NULL);
}

t_character		*find_player_c(int fd, t_tile *root, server_t *serv)
{
	int x = 0;
	int y = 0;
	t_tile *tmp = root;

	while (y != serv->args->height - 1)
		{
			while (x != serv->args->width - 1)
				{
					if (is_player_here_c(fd, root) != NULL)
						return (is_player_here_c(fd, root));
					root = root->right;
					x++;
				}
			x = 0;
			y++;
			root = tmp->down;
			tmp = tmp->down;
		}
	return (NULL);
}