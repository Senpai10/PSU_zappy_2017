/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Tests for list2 file
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, list2)
{
	list_res_t *list;
	list_res_t *tmp;
	char *look_cmd = strdup("Look");
	char *res = strdup("first message");
	char *res2 = strdup("second message");
	bool ret;

	if (!look_cmd || !res || !res2)
		exit(84);
	list = initiate_list_res(look_cmd);
	cr_assert(list != NULL);
	ret = add_list_msg(list, res);
	cr_assert(ret == true);
	tmp = get_last_elem(list);
	cr_assert(strcmp(tmp->cmd, "Message") == 0);
	ret = add_list_msg(list, res2);
	cr_assert(ret == true);
	ret = check_list_res(list, "second message");
	cr_assert(ret == true);
}
