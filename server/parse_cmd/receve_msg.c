/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** read_cmd
*/

#include "server.h"

/**
* \brief Parse the content from the fd.
*
* \param cmd The line send from the client.
* \param serv A pointer to the server structure.
* \param new_fd The new fd of the client.
* \param stream The FILE stream eof the client.
* \return int Return sucess or error.
*/
int	parse_cmd(char *cmd, server_t *serv, int new_fd, FILE *stream)
{
	char	**cmd_tab = str_to_wordtab(cmd);

	if (cmd_tab == NULL || cmd_tab[0] == NULL)
		return (ERR);
	if (strcmp(cmd_tab[0], "GRAPH") == SUCCESS_RET) {
		if (graph_cmd(cmd_tab, serv, new_fd, stream) == ERR)
			return (ERR);
	} else {
		if (ai_cmd(cmd_tab, serv, new_fd) == ERR)
			return (ERR);
	}
	return (SUCCESS_RET);
}

/**
* \brief Read the content from a fd.
*
* \param client_fd The client fd who send a msg.
* \param serv A pointer to a server structure.
* \return int Return sucess or error.
*/
int	receve_msg(int client_fd, server_t *serv)
{
	FILE	*stream = fdopen(client_fd, "rw");
	char	*cmd;

	if (stream == NULL)
		return (ERR);
	cmd = get_line(stream);
	if (cmd == NULL) {
		return (SUCCESS_RET);
	}
	if (parse_cmd(cmd, serv, client_fd, stream) == ERR)
		return (ERR);
	return (SUCCESS_RET);
}