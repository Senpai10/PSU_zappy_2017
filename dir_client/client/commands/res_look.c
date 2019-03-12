/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look
*/

#include "client.h"

int check = 0;

/**
* @brief Run toward the caller (broadcast) if there is a sound
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) The linked list which stock the commands and
* reponses
* @param str (char *) The object (player, food, or stone) on the till
* @param tile (int) The tile's number
* @return list_res_t* return the linked list with several new commands to get
* the object
*/
list_res_t *run_toward_caller(client_t *self, list_res_t *head, char *str,
				int tile)
{
	if (my_strcmp("player", str) == 0) {
		check = 1;
		return (move_command(self, head, tile));
	}
	return (head);
}


/**
* @brief Choose the object needed on the tile
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) The linked list which stock the commands and
* reponses
* @param str (char *) The object on the till
* @param tile (int) The tile's number
* @return list_res_t* return the linked list with several new commands to get
* the object
*/
list_res_t *choose_object_on_tile(client_t *self, list_res_t *head, char *str,
				int tile)
{
	if ((self->role & r_listener) && (self->state & n_ritual)) {
		head = run_toward_caller(self, head, str, tile);
	} else {
		if ((self->state & n_food)
		&& my_strcmp("food", str) == 0) {
			head = move_command(self, head, tile);
			return (take_object(self, head, "food"));
		}
		head = need_mineral(self, head, str, tile);
	}
	if (head == NULL)
		return (NULL);
	return (head);
}

/**
* @brief If there are multiple object on one tile, parse and choose the object
* needed
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) The linked list which stock the commands and
* reponses
* @param str (char *) All of the object inside the till
* @param tile (int) The tile's number
* @return list_res_t* return the linked list with several new commands to get
* the object
*/
list_res_t *multiple_object(client_t *self, list_res_t *head,
			char *str, int tile)
{
	char **multiple_obj = stw(str, ' ');
	list_res_t *last_elem = get_last_elem(head);

	if (multiple_obj == NULL)
		return (NULL);
	for (int i = 0; multiple_obj[i] != NULL; i++) {
		head = choose_object_on_tile(self, head, multiple_obj[i],
			tile);
		if (new_command_or_not(head, last_elem) == true) {
			free_tab(multiple_obj);
			return (head);
		}
	}
	free_tab(multiple_obj);
	return (head);
}

/**
* @brief This function check the vision if an object needed is in his vision
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) The linked list which stock the commands and
* reponses
* @param parsed (char **) His vision parsed in char **
* @return list_res_t* return the linked list with several new commands to get
* the object
*/
list_res_t *check_vision(client_t *self, list_res_t *head, char **parsed)
{
	list_res_t *last_elem = get_last_elem(head);

	for (int i = (self->role & r_listener) && (self->state & n_ritual) ?
	1 : 0; parsed[i] != NULL; i++) {
		if (count_word(parsed[i], ' ') >= 2)
			head = multiple_object(self, head, parsed[i], i);
		if (new_command_or_not(head, last_elem) == true)
			return (head);
		head = choose_object_on_tile(self, head, parsed[i], i);
		if (new_command_or_not(head, last_elem) == true)
			return (head);
	}
	if (!(self->role & r_listener))
		head = change_direction(self, head);
	return (head);
}

/**
* @brief According To the reponse of look, the IA will go on the tile to take
* an object needed
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) The linked list which stock the commands and
* reponses
* @return list_res_t* the linked list with several new commands to retrieve the
* object
*/
list_res_t *look_res(client_t *self, list_res_t *head)
{
	char **parsed = stw_look(head->res, ',');

	if (parsed == NULL)
		return (NULL);
	if (self->role & r_caller)
		head = take_everything(self, head, &(parsed[0][1]));
	else
		head = check_vision(self, head, parsed);
	free_tab(parsed);
	if ((self->role & r_listener) && check == 0)
		if (!request_cmd(self->sfd, head, "Forward"))
			return (NULL);
	if (head == NULL)
		return (NULL);
	return (head);
}
