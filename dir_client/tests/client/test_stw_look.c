/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test stw look
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, stw_look)
{
	char **tab = stw_look("player,,,]", ',');
	char **tab2 = stw_look("player,linemate sibur, phiras,]", ',');
	int value = 0;

	if (tab == NULL || tab2 == NULL)
		exit(84);
	for (int i = 0; tab[i] != NULL; i++)
		value++;
        cr_assert(value == 4);
	value = 0;
	for (int i = 0; tab2[i] != NULL; i++)
		value++;
        cr_assert(value == 4);
	free_tab(tab);
	free_tab(tab2);
}