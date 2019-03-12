/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** update state life
*/

#include "client.h"

/**
* @brief Check if food is needed or not
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void update_needs_life(client_t *self, char **parsed)
{
	for (int i = 0; parsed[i] != NULL; i++) {
		if (my_strncmp("food", parsed[i], 4) == 0
		&& get_quantity(parsed[i]) <= 8 && (!(self->state & n_food)))
			self->state += n_food;
		else if (my_strncmp("food", parsed[i], 4) == 0
		&& get_quantity(parsed[i]) >= 15 && (self->state & n_food))
			self->state -= n_food;
	}
}