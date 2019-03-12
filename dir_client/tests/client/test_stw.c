/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Test file for stw
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, stw)
{
	char **tab;
	char *simple_line = strdup("    This   is    a   message.    ");

	if (!simple_line)
		exit(84);
	tab = stw(simple_line, ' ');
	cr_assert(tab);
	cr_assert(strcmp(tab[0], "This") == 0);
	cr_assert(strcmp(tab[1], "is") == 0);
	cr_assert(strcmp(tab[2], "a") == 0);
	cr_assert(strcmp(tab[3], "message.") == 0);
	free_tab(tab);
}
