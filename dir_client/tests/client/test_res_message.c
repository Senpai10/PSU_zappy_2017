/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** test file for message resolve
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, res_message_call_no_role)
{
	list_res_t *head = malloc(sizeof(struct s_list_res));
	client_t self = {1, 1, 15, 0, 0, 128, 2, "RED", NULL};

	if (!head)
		exit(84);
	head->cmd = strdup("Message");
	head->res = strdup("message 1, .RED 1 18, 2 1");
	if (!head->cmd || !head->res)
		exit(84);
	head = handle_message(&self, head);
	cr_assert(head != NULL);
	cr_assert(self.role == r_listener);
	cr_assert(self.r_act == 18);
	cr_assert(strcmp("Look", head->next->cmd) == 0);
	destroy_list_res(head);
}

Test(assert, res_message_call_caller_inferior)
{
	list_res_t *head = malloc(sizeof(struct s_list_res));
	client_t self = {1, 1, 15, 0, r_caller, 128, 2, "RED", NULL};

	if (!head)
		exit(84);
	head->cmd = strdup("Message");
	head->res = strdup("message 1, .RED 1 18, 2 1");
	if (!head->cmd || !head->res)
		exit(84);
	head = handle_message(&self, head);
	cr_assert(head != NULL);
	cr_assert(self.role == r_listener);
	cr_assert(self.r_act == 18);
	cr_assert(strcmp("Broadcast", head->next->cmd) == 0);
	destroy_list_res(head);
}

Test(assert, res_message_begin_actions_when_not_there)
{
	list_res_t *head = malloc(sizeof(struct s_list_res));
	client_t self = {1, 1, 15, 18, r_listener,
			128, 2, "RED", NULL};

	if (!head)
		exit(84);
	head->cmd = strdup("Message");
	head->res = strdup("message 1, .RED 3 18");
	if (!head->cmd || !head->res)
		exit(84);
	head = handle_message(&self, head);
	cr_assert(head != NULL);
	cr_assert(self.role == r_caller);
	cr_assert(self.r_act == 1);
	cr_assert(strcmp("Broadcast", head->next->cmd) == 0);
	destroy_list_res(head);
}

Test(assert, res_message_begin_action_when_present)
{
	list_res_t *head = malloc(sizeof(struct s_list_res));
	client_t self = {1, 1, 15, 18, 0,
			 128, 2, "RED", NULL};

	if (!head)
		exit(84);
	self.role = r_listener + r_present;
	head->cmd = strdup("Message");
	head->res = strdup("message 0, .RED 3 18");
	if (!head->cmd || !head->res)
		exit(84);
	head = handle_message(&self, head);
	cr_assert(head != NULL);
	cr_assert(head->next != NULL);
	cr_assert(strcmp("Look", head->next->cmd) == 0);
	destroy_list_res(head);
}

Test(assert, res_message_there_client)
{
	list_res_t *head = malloc(sizeof(struct s_list_res));
	client_t self = {1, 1, 18, 1, r_caller,
			 128, 2, "RED", NULL};

	if (!head)
		exit(84);
	head->cmd = strdup("Message");
	head->res = strdup("message 0, .RED 4 15");
	if (!head->cmd || !head->res)
		exit(84);
	head = handle_message(&self, head);
	cr_assert(self.r_act == 0);
	cr_assert(head != NULL);
	cr_assert(head->next != NULL);
	cr_assert(strcmp("Broadcast", head->next->cmd) == 0);
	destroy_list_res(head);
}
