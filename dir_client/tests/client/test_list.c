/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test linked list
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, list)
{
	char *cmd_one = strdup("Look");
	char *cmd_two = strdup("Forward");
	char *response = strdup("ok");
	char *response2 = strdup("ok");
	list_res_t *list;
	bool value;

	if (!cmd_one || !cmd_two || !response || !response2)
		exit(84);
	list = initiate_list_res(cmd_one);
	cr_assert(list != NULL);
	value = add_list_res(list, response);
	cr_assert(value == true);
	value = add_list_cmd(list, cmd_two);
	cr_assert(value == true);
	value = add_list_res(list, response);
	cr_assert(value == true);
	list = destroy_list_res(list);
	cr_assert(list == NULL);
}
