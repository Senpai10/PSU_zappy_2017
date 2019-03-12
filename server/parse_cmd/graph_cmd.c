/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** graph_cmd
*/

#include "server.h"

/**
* \brief
*
* \param new_fd The fd of the graphic client.
* \param stream The FILE stream of the graphic client.
* \param serv A pointer to the server structure.
* \return int Return sucess or retrun.
*/
static int	first_graph_connection(int new_fd, FILE *stream
					, server_t *serv)
{
	graph_clt_t	*graph = malloc(sizeof(graph_clt_t));

	if (graph == NULL)
		return (ERR);
	graph->fd = new_fd;
	graph->stream = stream;
	serv->g_clt = graph;
	dprintf(new_fd, "msz %d %d\n", serv->args->width, serv->args->height);
	send_map_content(serv);
	return (SUCCESS_RET);
}

/**
* \brief Check the command of the graphical client.
*
* \param cmd The double array of the command receve.
* \param serv A pointer to the server structure.
* \param new_fd The fd of the graphic client.
* \param stream The FILE stream of the graphic client.
* \return int Return sucess or error.
*/
int	graph_cmd(char **cmd, server_t *serv, int new_fd, FILE *stream)
{
	if (strcmp(cmd[1], "1") == SUCCESS_RET)
		if (first_graph_connection(new_fd, stream, serv) == ERR)
			return (ERR);
	return (SUCCESS_RET);
}