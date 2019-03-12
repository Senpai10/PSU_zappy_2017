/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** get quantty
*/

#include "client.h"

/**
* @brief Get the stone's quantity in inventory
*
* @param str (char *) which contains the name of stone and the quantity
* @return int return the stone's quantity
*/
int get_quantity(char *str)
{
	char **parsed = stw(str, ' ');
	int quantity;

	if (!parsed || parsed[1] == NULL)
		return (-1);
	quantity = atoi(parsed[1]);
	free_tab(parsed);
	return (quantity);
}