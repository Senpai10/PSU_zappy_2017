/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ia
*/

#include "client.h"

const commands_res_t commands_tab[] =
{
	{"Forward", &handle_ok_res},
	{"Right", &handle_ok_res},
	{"Left", &handle_ok_res},
	{"Look", &look_res},
	{"Inventory", &inventory_res},
	{"Broadcast", &broadcast_res},
	{"Fork", &handle_ok_res},
        {"Team_initial", &team_initial_res},
	{"Team_num", &team_num_res},
	{"Team_map", &team_map_res},
        {"Take", &take_object_res},
	{"Set", &handle_ok_res},
	{"Incantation", &ritual_res_active},
	{"Ritual End", &ritual_res_end},
	{"Message", &handle_message},
	{"Connect_nbr", &connect_nbr_res},
        {NULL, NULL}
};

/**
* @brief Start the IA
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @return list_res_t* return the linked list
*/
list_res_t *ia(client_t *self, list_res_t *head)
{
	list_res_t *tmp = head;
	int i = 0;

	while (commands_tab[i].name != NULL) {
		if (strcmp(commands_tab[i].name, head->cmd) == 0)
			tmp = commands_tab[i].fct_commands(self, head);
		i++;
	} if (!tmp) {
		exit_error = true;
		destroy_list_res(head);
		return (NULL);
	}
	head = tmp;
	head = del_list_res(head);
	return (head);
}
