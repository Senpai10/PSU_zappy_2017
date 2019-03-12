/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** file for id creation
*/

#include "client.h"

/**
* @brief Create a random id for each IA
*
* @return int the id
*/
int create_random_id(void)
{
	srand(time(NULL));
	return (rand());
}
