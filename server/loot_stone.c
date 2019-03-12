/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** loot_stone
*/

#include "server.h"

void	loot_linemate(t_character *charac)
{
	charac->linemate = charac->linemate + 1;
}

void	loot_deraumere(t_character *charac)
{
	charac->deraumere = charac->deraumere + 1;
}

void	loot_sibur(t_character *charac)
{
	charac->sibur = charac->sibur + 1;
}

void	loot_mendiane(t_character *charac)
{
	charac->mendiane = charac->mendiane + 1;
}

void	loot_phiras(t_character *charac)
{
	charac->phiras = charac->phiras + 1;
}