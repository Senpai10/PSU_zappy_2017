/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check if there is a new command
*/

#include "client.h"

/**
* @brief Check if in the linked list we have a new command or not
*
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param last_elem (list_res_t *) The linked list's last element previously
* copied
* @return true if there are new commands
* @return false if there aren't new commands
*/
bool new_command_or_not(list_res_t *head, list_res_t *last_elem)
{
	list_res_t *tmp = head;

	if (head == NULL)
		return (true);
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (last_elem != tmp)
		return (true);
	return (false);
}

/**
* @brief (Second part) Check if there are a stone needed on the tile, if
* there are, move toward the object and take
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param object The object's name on the tile
* @param tile (int) The tile's number
* @return list_res_t* return the linked list with several new commands to get
* the object needed
*/
list_res_t *need_mineral2(client_t *self, list_res_t *head, char *object,
			int tile)
{
	if ((self->state & n_mendiane)
	&& my_strcmp("mendiane", object) == 0) {
		head = move_command(self, head, tile);
		return (take_object(self, head, "mendiane"));
	} if ((self->state & n_phiras)
	&& my_strcmp("phiras", object) == 0) {
		head = move_command(self, head, tile);
		return (take_object(self, head, "phiras"));
	} if ((self->state & n_thystame)
	&& my_strcmp("thystame", object) == 0) {
		head = move_command(self, head, tile);
		return (take_object(self, head, "thystame"));
	}
	return (head);
}

/**
* @brief (First part) Check if there are a stone needed on the tile, if
* there are, move toward the object and take
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param object The object's name on the tile
* @param tile (int) The tile's number
* @return list_res_t* return the linked list with several new commands to get
* the object needed
*/
list_res_t *need_mineral(client_t *self, list_res_t *head, char *object,
			int tile)
{
	if ((self->state & n_linemate)
	&& my_strcmp("linemate", object) == 0) {
		head = move_command(self, head, tile);
		return (take_object(self, head, "linemate"));
	} if ((self->state & n_deraumere)
	&& my_strcmp("deraumere", object) == 0) {
		head = move_command(self, head, tile);
		return (take_object(self, head, "deraumere"));
	} if ((self->state & n_sibur)
	&& my_strcmp("sibur", object) == 0) {
		head = move_command(self, head, tile);
		return (take_object(self, head, "sibur"));
	}
	return (need_mineral2(self, head, object, tile));
}

/**
* @brief Take everything on the tile to do an incantation
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param tile (int) The tile's number
* @return list_res_t* return the linked list with several new commands to get
* all the object on the tile
*/
list_res_t *take_everything(client_t *self, list_res_t *head, char *tile)
{
	char **objects_list = stw(tile, ' ');

	if (!objects_list)
		return (NULL);
	for (int i = 0; objects_list[i]; i++) {
		if (strcmp("player", objects_list[i]) != 0)
			head = take_object(self, head, objects_list[i]);
		if (!head) {
			free_tab(objects_list);
			return (NULL);
		}
	}
	if (self->r_act == 0) {
		free_tab(objects_list);
		return (start_ritual(self, head));
	}
	head = request_broadcast_call(self, head);
	free_tab(objects_list);
	return (head);
}
