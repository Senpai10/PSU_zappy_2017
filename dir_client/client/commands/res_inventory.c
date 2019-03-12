/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look res
*/

#include "client.h"

const level_t level_tab[] =
{
	&need_for_lvl_one,
	&need_for_lvl_two,
	&need_for_lvl_three,
	&need_for_lvl_four,
	&need_for_lvl_five,
	&need_for_lvl_six,
	&need_for_lvl_seven,
	NULL
};

/**
* @brief Change his state to evolve if he have the requirement to pass level 5
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_four(client_t *self, char **parsed)
{
	for (int i = 0; parsed[i] != NULL; i++) {
		if (my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_linemate))
			self->state -= n_linemate;
		if (my_strncmp("deraumere", parsed[i], 9) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_deraumere))
			self->state -= n_deraumere;
		if (my_strncmp("sibur", parsed[i], 5) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_sibur))
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
* @brief Change his state to evolve if he have the requirement to pass level 4
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_three(client_t *self, char **parsed)
{
	for (int i = 0; parsed[i] != NULL; i++) {
		if (my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_linemate))
			self->state -= n_linemate;
		if (my_strncmp("sibur", parsed[i], 5) == 0
		&& get_quantity(parsed[i]) >= 1 && (self->state & n_sibur))
			self->state -= n_sibur;
		if (my_strncmp("phiras", parsed[i], 6) == 0
		&& get_quantity(parsed[i]) >= 2 && (self->state & n_phiras))
			self->state -= n_phiras;
	} if (!(self->state & n_ritual) && (!(self->state & n_linemate)
	&& !(self->state & n_sibur) && !(self->state & n_phiras)))
		self->state += n_ritual;
}

/**
* @brief Change his state to evolve if he have the requirement to pass level 3
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_two(client_t *self, char **parsed)
{
	int i = 0;

	while (parsed[i] != NULL) {
		if ((self->state & n_linemate)
		&& my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 1)
			self->state -= n_linemate;
		if ((self->state & n_deraumere) &&
		my_strncmp("deraumere", parsed[i], 9) == 0
		&& get_quantity(parsed[i]) >= 1)
			self->state -= n_deraumere;
		if ((self->state & n_sibur) &&
		my_strncmp("sibur", parsed[i], 5) == 0
		&& get_quantity(parsed[i]) >= 1)
			self->state -= n_sibur;
		i++;
	} if (!(self->state & n_ritual) && (!(self->state & n_linemate)
	&& !(self->state & n_deraumere) && !(self->state & n_sibur)))
		self->state += n_ritual;
}

/**
* @brief Change his state to evolve if he have the requirement to pass level 2
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param parsed (char **) The inventory parsed in char **
*/
void need_for_lvl_one(client_t *self, char **parsed)
{
	int i = 0;

	while (parsed[i] != NULL) {
		if ((self->state & n_linemate)
		&& my_strncmp("linemate", parsed[i], 8) == 0
		&& get_quantity(parsed[i]) >= 1)
			self->state -= n_linemate;
		i++;
	} if (!(self->state & n_ritual) && !(self->state & n_linemate))
		self->state += n_ritual;
}

/**
* @brief According to the response of Inventory, change his flags, what he need
* and put the command look in the queue
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) The linked list which stock the commands and
* reponses
* @return list_res_t* return the linked list with new command and his state is
* updated for what he need
*/
list_res_t *inventory_res(client_t *self, list_res_t *head)
{
	char **parsed = stw(head->res, ',');

	if (!parsed)
		return (NULL);
	update_needs_life(self, parsed);
	level_tab[self->level - 1](self, parsed);
	if (self->state & n_ritual && !(self->state & n_food)) {
		if (!enter_ritual_state(self, head)) {
			free_tab(parsed);
			return (NULL);
		}
	} else if (!request_cmd(self->sfd, head, "Look")) {
		free_tab(parsed);
		return (NULL);
	}
	free_tab(parsed);
	return (head);
}
