/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** list related functions for client
*/

#include "client.h"

/**
* @brief Initialize the linked list
*
* @param cmd (char *) The command that we want to put in the linked list
* @return list_res_t* return the linked list initialized
*/
list_res_t *initiate_list_res(char *cmd)
{
	list_res_t *head = malloc(sizeof(struct s_list_res));

	if (!head)
		return (NULL);
	head->next = NULL;
	head->cmd = strdup(cmd);
	head->res = NULL;
	if (!head->cmd) {
		free(head);
		return (NULL);
	}
	return (head);
}

/**
* @brief Add a new command in the linked list
*
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param cmd The new command that we want to put in the linked list
* @return true If there are no problem
* @return false If we cannot put the new command in the linked list
*/
bool add_list_cmd(list_res_t *head, char *cmd)
{
	list_res_t *node = malloc(sizeof(struct s_list_res));
	list_res_t *tmp = head;

	if (!node)
		return (false);
	node->next = NULL;
	node->cmd = strdup(cmd);
	node->res = NULL;
	if (!node->cmd) {
		free(node);
		return (false);
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (true);
}

/**
* @brief Add a new response in the linked list
*
* @param head (list_res_t *) Linked list which contains commands and responses
* reponses
* @param line The response that we want to put in the linked list
* @return true If there are no problem
* @return false If we cannot put the new reponse in the linked list
*/
bool add_list_res(list_res_t *head, char *line)
{
	list_res_t *tmp = head;

	while (tmp && tmp->res)
		tmp = tmp->next;
	if (tmp)
		tmp->res = line;
	else
		return (false);
	return (true);
}

/**
* @brief Free each element in the linked list
*
* @param head (list_res_t *) The linked list that we want to free and destroy
* @return list_res_t* return the linked list free
*/
list_res_t *del_list_res(list_res_t *head)
{
	list_res_t *node = head;

	if (!node)
		return (NULL);
	head = head->next;
	if (node->cmd)
		free(node->cmd);
	if (node->res)
		free(node->res);
	free(node);
	return (head);
}

/**
* @brief Destroy the linked list
*
* @param head (list_res_t *) The linked list that we want to destroy
* @return list_res_t* return NULL
*/
list_res_t *destroy_list_res(list_res_t *head)
{
	list_res_t *tmp = head;
	list_res_t *node;

	while (tmp) {
		node = tmp;
		tmp = tmp->next;
		del_list_res(node);
	}
	return (NULL);
}
