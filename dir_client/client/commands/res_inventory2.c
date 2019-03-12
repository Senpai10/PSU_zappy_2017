/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inventory res part two
*/

#include "client.h"

/**
* @brief (Part 2) Change his state to evolve if he have the requirement to pass
* level 8
*
* @param self (client_t *) The struct which contains several information about
* IA
*/
void return_need_for_lvl_seven(client_t *self)
{
	if (!(self->state & n_ritual) && (!(self->state & n_linemate)
	&& !(self->state & n_deraumere) && !(self->state & n_sibur)
	&& !(self->state & n_mendiane) && !(self->state & n_phiras)
	&& !(self->state & n_thystame)))
		self->state += n_ritual;
}

/**
* @brief (Part 2) Change his state to evolve if he have the requirement to pass
* level 8
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
* @param i (int) The index that where we are in the char **
*/
void need_for_lvl_seven2(client_t *self, char **parsed, int i)
{
	if (my_strncmp("mendiane", parsed[i], 8) == 0
	&& get_quantity(parsed[i]) >= 2 && (self->state & n_mendiane))
		self->state -= n_mendiane;
	if (my_strncmp("phiras", parsed[i], 6) == 0
	&& get_quantity(parsed[i]) >= 2 && (self->state & n_phiras))
		self->state -= n_phiras;
	if (my_strncmp("thystame", parsed[i], 8) == 0
	&& get_quantity(parsed[i]) >= 1 && (self->state & n_thystame))
		self->state -= n_thystame;
}

/**
* @brief (Part 1) Change his state to evolve if he have the requirement to pass
* level 8
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_seven(client_t *self, char **parsed)
{
	for (int i = 0; parsed[i] != NULL; i++) {
		if (my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_linemate))
			self->state -= n_linemate;
		if (my_strncmp("deraumere", parsed[i], 9) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_deraumere))
			self->state -= n_deraumere;
		if (my_strncmp("sibur", parsed[i], 5) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_sibur))
			self->state -= n_sibur;
		need_for_lvl_seven2(self, parsed, i);
	}
	return_need_for_lvl_seven(self);
}

/**
* @brief Change his state to evolve if he have the requirement to pass level 7
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_six(client_t *self, char **parsed)
{
	for (int i = 0; parsed[i] != NULL; i++) {
		if (my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_linemate))
			self->state -= n_linemate;
		if (my_strncmp("deraumere", parsed[i], 9) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_deraumere))
			self->state -= n_deraumere;
		if (my_strncmp("sibur", parsed[i], 5) == 0
		&& get_quantity(parsed[i]) >= 3 && (self->state & n_sibur))
			self->state -= n_sibur;
		if (my_strncmp("phiras", parsed[i], 6) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_phiras))
			self->state -= n_phiras;
	} if (!(self->state & n_ritual) && (!(self->state & n_linemate)
	&& !(self->state & n_deraumere) && !(self->state & n_sibur)
	&& !(self->state & n_phiras)))
		self->state += n_ritual;
}

/**
* @brief Change his state to evolve if he have the requirement to pass level 6
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_five(client_t *self, char **parsed)
{
	for (int i = 0; parsed[i] != NULL; i++) {
		if (my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_linemate))
			self->state -= n_linemate;
		if (my_strncmp("deraumere", parsed[i], 9) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_deraumere))
			self->state -= n_deraumere;
		if (my_strncmp("sibur", parsed[i], 5) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_sibur))
			self->state -= n_sibur;
		if (my_strncmp("mendiane", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 3 && (self->state & n_mendiane))
			self->state -= n_mendiane;
	} if (!(self->state & n_ritual) && (!(self->state & n_linemate)
	&& !(self->state & n_deraumere) && !(self->state & n_sibur)
	&& !(self->state & n_mendiane)))
		self->state += n_ritual;
}