/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

/**
* @file main.cpp
* @brief fonction main qui initialise et lance le client graphique
* @author lmaignan et mgayaud
*
* Fichier contenant la fonction main du client graphique, qui initalise et
* lance respectivement l'introduction, le menu, l'écran de connexion et la
* simulation
*
*/

#include "../include/ZappyGraphic.hpp"

/**
* @brief initialise et lance le client graphique
*
* @return 84 en cas d'erreur sinon 0
*/

int main()
{
	GameMenu menu;
	ConnectServer server(menu.getWindow());
	MenuControllers copyControll;

	if (menu.displayIntro() == -1)
		return 84;
	if (menu.displayLoop() == -1)
		return 84;
	copyControll = menu.getControll();
	if (copyControll.getState() == 4)
		if (server.startConnect() == -1)
			return -1;
	MainGame game(menu.getWindow(), server.getSocket());
	if (game.startGame() == -1)
		return 84;
	return 0;
}