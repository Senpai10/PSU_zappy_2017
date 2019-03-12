/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** free functions for tab
*/

#include "releaser.h"

/**
* @brief free elements in tab and tab herself
*
* @param tab (char **) contain the tab to free
*/
void free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}
