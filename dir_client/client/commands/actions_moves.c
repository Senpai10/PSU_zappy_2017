/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** move functions and command
*/

#include "client.h"

/**
* @brief Move randomly if the IA don't find an object needed on his side
*
* @param self (client_t *) the struct which contains information about the IA
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t* return the linked list with new commands
*/
list_res_t *move_randomly(client_t *self, list_res_t *head)
{
	int nb;
	int level = self->level;

	srand(time(NULL));
	nb = rand() % 4;
	while (nb != 0) {
		if (!request_cmd(self->sfd, head, "Right"))
			return (NULL);
		nb--;
	} while (level != 0) {
		if (!request_cmd(self->sfd, head, "Forward"))
			return (NULL);
		level--;
	}
	if (!request_cmd(self->sfd, head, "Look"))
		return (NULL);
	return (head);
}

/**
* @brief Change his direction if he don't find anything on one of his side
*
* @param self (client_t *) Struct which contains several information about AI
* @param head (list_res_t *) Linked list which contains commands and responses
* @return list_res_t * return the linked list with new cmd and response
*/
list_res_t *change_direction(client_t *self, list_res_t *head)
{
	static int side = 0;

	if (side < 4) {
		if (!request_cmd(self->sfd, head, "Right") ||
		!request_cmd(self->sfd, head, "Look"))
			return (NULL);
		side++;
	} else {
		head = move_randomly(self, head);
		if (head == NULL)
			return (NULL);
		side = 0;
	}
	return (head);
}

/**
* @brief Retrieve the sum of (2n + 1)
*
* @param i (int) represent the variable n
* @return int that contain the sum
*/
static int sum_2n_p1(int i)
{
	int res = 0;

	for (int n = 0; n <= i; n++)
		res += (2 * n) + 1;
	return (res);
}

/**
* @brief change the player direction and forward until it reach the tile
*
* @param sfd (int) contain the socket fd
* @param head (list_res_t *) Linked list which contains commands and responses
* @param sidestr (char *) contain the string request to change direction
* @param i (int) iterator representing the number of times to forward
* @return list_res_t* containing the head or null if an error occurs
*/
static list_res_t *move_side(int sfd, list_res_t *head, char *sidestr, int i)
{
	if (i)
		if (!request_cmd(sfd, head, sidestr))
			return (NULL);
	while (i > 0) {
		if (!request_cmd(sfd, head, "Forward"))
			return (NULL);
		i--;
	}
	return (head);
}

/**
* @brief allow the player to walk to the given tile
*
* @param self (client_t *) contain informations about AI and client
* @param head (list_res_t *) Linked list which contains commands and responses
* @param t (int) tile index to reach
* @return list_res_t* containing the head or null if an error occurs
*/
list_res_t *move_command(client_t *self, list_res_t *head, int t)
{
	int n = 0;
	int side;

	while (!(t >= (sum_2n_p1(n) - ((2 * n) + 1)) &&
		t < sum_2n_p1(n)) && n <= self->level) {
		if (!request_cmd(self->sfd, head, "Forward")) {
		destroy_list_res(head);
			return (NULL);
		}
		n++;
	}
	side = (t + n + 1) - sum_2n_p1(n);
	head = (side > 0) ? move_side(self->sfd, head, "Right", side) :
		move_side(self->sfd, head, "Left", -side);
	return (head);
}
