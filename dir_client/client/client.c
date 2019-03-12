/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client loop and initialization
*/

#include "client.h"

const int n_linemate = 1;
const int n_deraumere = 2;
const int n_sibur = 4;
const int n_mendiane = 8;
const int n_phiras = 16;
const int n_thystame = 32;
const int n_food = 64;
const int n_ritual = 128;

const int r_listener = 1;
const int r_caller = 2;
const int r_present = 4;

/**
* @brief Monitore the client
*
* @param self (client_t *) The struct which contains several information about
* IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return true if there are no problem
* @return false if there are a problem
*/
bool epoll_wait_loop(client_t *self, list_res_t **head)
{
	int n = epoll_wait(self->efd, self->events, 64, -1);

	for (int i = 0; i < n; i++) {
		if (!get_responses_buffer(self, head, i))
			return (false);
	}
	return (true);
}

/**
* @brief Start the looping and wait the client's death
*
* @param self (client_t *) The struct which contains several information about
* IA
* @return true if there are no problem
* @return false if there are a problem
*/
bool start_looping(client_t *self)
{
	list_res_t *responses = initiate_list_res("Team_initial");

	while (!check_list_res(responses, "dead")) {
		if (!epoll_wait_loop(self, &responses)) {
			free(self->events);
			return (false);
		}
	}
	destroy_list_res(responses);
	return (true);
}

/**
* @brief Initialize the client and connect to the server
*
* @param host (char *) the host
* @param port (int) the port
* @param team (char *) the name of the team
* @return true If there are no problem
* @return false If there are a problem
*/
bool client_initialization(char *host, char *port, char *team)
{
	client_t self;

	self.level = 1;
	self.state = 1;
	self.team = team;
	self.role = 0;
	self.id = create_random_id();
	if (!connect_to_server(host, port, &self) ||
	self.sfd == -1 || !start_looping(&self)) {
		return (false);
	}
	free(self.events);
	return (true);
}
