/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** second file for lists related functions
*/

#include "client.h"

/**
* @brief Get the last elem in linked list
*
* @param head The linked list
* @return list_res_t* return the last element of linked list
*/
list_res_t *get_last_elem(list_res_t *head)
{
	list_res_t *tmp = head;

	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

/**
* @brief Check if the given line have a response occurence in the list
*
* @param head (list_res_t *) Linked list which contains commands and responses
* @param line (char *) line to compare the results with
* @return true if an occurence was found
* @return false otherwise
*/
bool check_list_res(list_res_t *head, char *line)
{
	list_res_t *tmp = head;

	while (tmp) {
		if (tmp->res && !strcmp(tmp->res, line))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/**
* @brief add the response buffer to the last command
*
* @param head (list_res_t *) Linked list which contains commands and responses
* @param line (char *) line to compare the results with
* @return true if no free response buffer was found
* @return false if an error occurs
*/
bool add_list_res_on_end(list_res_t *head, char *line)
{
	list_res_t *tmp = head;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->res = line;
	else
		return (false);
	return (true);
}

/**
* @brief add a message element into the linked list
*
* @param head (list_res_t *) Linked list which contains commands and responses
* @param res (char *) contains the response buffer
* @return true if every function end correctly
* @return false if an error occurs
*/
bool add_list_msg(list_res_t *head, char *res)
{
	list_res_t *tmp = head;

	while (tmp && strcmp("Message", tmp->cmd) != 0)
		tmp = tmp->next;
	if (tmp) {
		if (tmp->res)
			free(tmp->res);
		tmp->res = res;
		return (true);
	} else if (!add_list_cmd(head, "Message") ||
		!add_list_res_on_end(head, res))
		return (false);
	return (true);
}
