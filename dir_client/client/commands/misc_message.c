/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** parser for broadcasted message
*/

#include "client.h"
#include "messages.h"

const message_parsers msg_tab[] = {
	&parse_message_tile,
	&parse_message_player,
	&parse_message_optional
};

/**
* @brief last part of the message containing calling details
*
* @param (message_t **) address of the msg struct
* @param line (char *) first bloc of the parsed message
*/
static void parse_message_optional(message_t **msg, char *line)
{
	char **tab;

	tab = stw(line, ' ');
	if (!tab || !tab[0] || !tab[1]) {
		(*msg)->level = -1;
		(*msg)->nb_needed = -1;
		if (tab)
			free_tab(tab);
		return ;
	}
	(*msg)->level = atoi(tab[0]);
	(*msg)->nb_needed = atoi(tab[1]);
	free_tab(tab);
}

/**
* @brief parse the second part containing the action index and msg sender id
*
* @param msg (message_t **) address of the msg struct
* @param line (char *) first bloc of the parsed message
*/
static void parse_message_player(message_t **msg, char *line)
{
	char **tab;

	tab = stw(line, ' ');
	if (!tab)
		return ;
	else if (!tab[0] || !tab[1] || !tab[2] || *tab[0] != '.') {
		if (tab)
			free_tab(tab);
		return ;
	}
	(*msg)->action = atoi(tab[1]);
	(*msg)->id = atoi(tab[2]);
	free_tab(tab);
}

/**
* @brief parse the first part of the message containing the receptive tile
*
* @param msg (message_t **) address of the msg struct
* @param line (char *) first bloc of the parsed message
*/
static void parse_message_tile(message_t **msg, char *line)
{
	char **tab;

	tab = stw(line, ' ');
	if (!tab)
		return ;
	else if (!tab[1])
		free_tab(tab);
	(*msg)->tile = atoi(tab[1]);
	free_tab(tab);
}

/**
* @brief check the message format and the team name
*
* @param line (char *) contain the whole message unparsed
* @param team (char *) contain the team name
* @return true if the message can be understood by the client
* @return false if the message cannot be parsed or belong to another team
*/
static bool verify_message_format(char *line, char *team)
{
	char *tmp;

	if (!line)
		return (NULL);
	tmp = strchr(line, '.');
	if (!tmp)
		return (NULL);
	if (!strncmp(team, &(tmp[1]), strlen(team)))
		return (true);
	return (false);
}

/**
* @brief parse the recieved message from other clients and fill a struct
*
* @param line (char *) contain the whole message unparsed
* @param team (char *) contain the team name
* @return message_t* containing all informations about the message
*/
message_t *parse_message(char *line, char *team)
{
	char **tab;
	message_t *msg = malloc(sizeof(struct s_message));

	if (!msg)
		return (NULL);
	msg->tile = -1;
	msg->action = 0;
	msg->id = -1;
	msg->level = 0;
	msg->nb_needed = -1;
	if (!verify_message_format(line, team))
		return (msg);
	tab = stw(line, ',');
	if (!tab)
		return (msg);
	for (int i  = 0; tab[i] && i < 3; i++) {
		msg_tab[i](&msg, tab[i]);
	}
	free_tab(tab);
	return (msg);
}