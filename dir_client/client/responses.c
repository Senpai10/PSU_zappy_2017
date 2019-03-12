/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** functions to parse and handle the responses from server
*/

#include "client.h"

bool exit_error = false;

/**
* @brief treat a single response and call the AI function
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param rep (char *) buffer containing a single response
* @return true if every calls end normally
* @return false if an error occurs
*/
bool handle_single_cmd(client_t *self, list_res_t **head, char *rep)
{
	if (!strncmp(rep, "message", 7)) {
		if (!(*head) || !add_list_msg((*head), rep))
			return (false);
		return (true);
	}
	if (!(*head) || !add_list_res((*head), rep))
		return (false);
	while ((*head) && (*head)->res) {
		if (strcmp("dead", (*head)->res) == 0 ||
		strcmp("", (*head)->res) == 0)
			return (true);
		(*head) = ia(self, (*head));
		if (exit_error)
			return (false);
	}
	return (true);
}

/**
* @brief parse the response buffer and treat every command separetly
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param buffer (char *) contains the response from the server
* @return true if every calls end normally
* @return false if an error occurs
*/
bool handle_responses(client_t *self, list_res_t **head, char *buffer)
{
	char **tab_commands = stw(buffer, '\n');

	if (!tab_commands) {
		destroy_list_res((*head));
		return (false);
	}
	for (int i = 0; tab_commands[i]; i++) {
		if (!handle_single_cmd(self, head, tab_commands[i])) {
			free(tab_commands);
			return (false);
		}
	}
	free(tab_commands);
	return (true);
}

/**
* @brief read the response on the server socket
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @param i (int) index of the events array that have triggered
* @return true if every calls end normally
* @return false if an error occurs
*/
bool get_responses_buffer(client_t *self, list_res_t **head, int i)
{
	char buf[512];
	int ret;

	if (self->events[i].data.fd == self->sfd)
		ret = recv(self->sfd, buf, 512, MSG_DONTWAIT);
	if (ret <= 0) {
		destroy_list_res((*head));
		return (false);
	}
	buf[ret] = '\0';
	if (!handle_responses(self, head, buf)) {
		destroy_list_res((*head));
		return (false);
	}
	return (true);
}
