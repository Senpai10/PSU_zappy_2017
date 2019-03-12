/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** miscellaneous functions for ritual
*/

#include "client.h"

/**
* @brief When there are some sound, turn to the side where we receive
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param tile Represent the tile (side) where we receive the sound
* @return list_res_t* return the linked list with new command to turn
*/
list_res_t *sound_reception(client_t *self, list_res_t *head, int tile)
{
	for (int i = 1; i < tile && (tile > 1 && tile <= 5); i += 2)
		if (!request_cmd(self->sfd, head, "Left"))
			return (NULL);
	for (int i = 9; i > tile && (tile > 5 && tile < 9); i -= 2)
		if (!request_cmd(self->sfd, head, "Right"))
			return (NULL);
	if (tile == 0 && !(self->role & r_present)) {
		self->role += r_present;
		return (request_broadcast(self, head, 4));
	} else {
		if (self->role & r_present)
			self->role -= r_present;
		return (request_cmd(self->sfd, head, "Look"));
	}
}

/**
* @brief Allows to know how many of players we need to evolve.
*
* @param level (int) The current level
* @return int return the number of player we need to evolve
*/
int players_needed_by_ritual(int level)
{
	int players_needed[] = {0, 1, 1, 3, 3, 5, 5};

	return (players_needed[level - 1]);
}
