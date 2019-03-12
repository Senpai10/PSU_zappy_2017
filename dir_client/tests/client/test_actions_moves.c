/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Test file for actions move
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, actions_moves)
{
	client_t self = {1, -1, -1, -1, -1, -1, 3, NULL, NULL};
	char *res = strdup("Look");
	list_res_t *head;
	list_res_t *tmp;

	if (!res)
		exit(84);
	head = initiate_list_res(res);
	cr_assert(head != NULL);
	head = move_command(&self, head, 3);
	tmp = head->next;
	cr_assert(strcmp(tmp->cmd, "Forward") == 0);
	cr_assert(strcmp(tmp->next->cmd, "Right") == 0);
	cr_assert(strcmp(tmp->next->next->cmd, "Forward") == 0);
	destroy_list_res(head);
}
