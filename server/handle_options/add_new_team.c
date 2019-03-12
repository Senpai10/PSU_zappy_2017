/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** add_new_team
*/

#include "server.h"

/**
* \brief Fill the structure client.
*
* \param new A pointer to the new team struct element.
* \param name The name of the client.
* \return int Return sucess or error.
*/
static int	fill_client(team_t *new, char *name)
{
	new->name = strdup(name);
	new->client = NULL;
	if (!new->name) {
		perror("Malloc: ");
		return (ERR);
	}
	return (SUCCESS_RET);
}

/**
* \brief Add the client struct in linked list.
*
* \param teams The begin pointer of team linked list.
* \param new New elem of team structure.
* \return int Return sucess or error.
*/
static int	add_client_at_list(team_t *teams, team_t *new)
{
	team_t *tmp = teams;

	for (; tmp; tmp = tmp->next) {
		if (!tmp->next) {
			tmp->next = new;
			new->next = NULL;
			return (SUCCESS_RET);
		}
	}
	return (SUCCESS_RET);
}

/**
* \brief Add a team to the game.
*
* \param serv A pointer to the args structure.
* \param name The name of the team.
* \return int Return sucess of error.
*/
int	add_new_team(args_t *serv, char *name)
{
	team_t	*tmp = malloc(sizeof(team_t));

	if (!tmp)
		return (ERR);
	if (!serv->teams) {
		serv->teams = tmp;
		serv->teams->next = NULL;
	} else
		add_client_at_list(serv->teams, tmp);
	if (fill_client(tmp, name) == ERR)
		return (ERR);
	return (SUCCESS_RET);
}