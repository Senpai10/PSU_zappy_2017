/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

/**
* @file MenuControllers.cpp
* @brief méthodes qui gèrent les entrées utilisateur du menu principal
* @author lmaignan et mgayaud
*
* Fichier contenant les méthodes qui sélectionnent et exécutent les options
* en fonction des entrées utilisateur
*
*/

#include "../include/ZappyGraphic.hpp"

/**
* @brief Construct a new Menu Controllers:: Menu Controllers object
*
*/

MenuControllers::MenuControllers()
{
	this->state = 1;
	this->initColors();
	this->menuFont.loadFromFile("./ressources/font/ka1.ttf");
	this->play.setFont(this->menuFont);
	this->play.setString("Play");
	this->play.setFillColor(this->light);
	this->play.setPosition(820, 450);
	this->play.setCharacterSize(70);
	this->options.setFont(this->menuFont);
	this->options.setString("Options");
	this->options.setFillColor(this->blue);
	this->options.setPosition(820, 650);
	this->options.setCharacterSize(70);
	this->exit.setFont(this->menuFont);
	this->exit.setString("exit");
	this->exit.setFillColor(this->blue);
	this->exit.setPosition(820, 850);
	this->exit.setCharacterSize(70);
}

/**
* @brief Destroy the Menu Controllers:: Menu Controllers object
*
*/

MenuControllers::~MenuControllers()
{

}

/**
* @brief affiche ce que l'utilisateur peut sélectionner
*
*/

void	MenuControllers::drawTitles()
{
	if (this->state == 1) {
		this->play.setFillColor(this->light);
		this->options.setFillColor(this->blue);
		this->exit.setFillColor(this->blue);
	}
	else if (this->state == 2) {
		this->play.setFillColor(this->blue);
		this->options.setFillColor(this->light);
		this->exit.setFillColor(this->blue);
	}
	else {
		this->play.setFillColor(this->blue);
		this->options.setFillColor(this->blue);
		this->exit.setFillColor(this->light);
	}
}

/**
* @brief synchronise l'attribut state pour le fonctionnement du programme
*
*/

void	MenuControllers::handleReturnState()
{
	if (this->state == 1)
		this->state = 4;
	if (this->state == 2) {
		this->state = 5;
		return ;
	}
	if (this->state == 3)
		this->state = 6;
}

/**
* @brief change la sélection de l'utilisateur selon l'entrée clavier
*
* @param event entrée clavier du l'utilisateur
*/

void	MenuControllers::handleState(const sf::Event event)
{
	if (this->state == 5) {
		if (event.key.code == sf::Keyboard::Return)
			this->state = 1;
		return;
	}
	if (event.key.code == sf::Keyboard::Down) {
		if (this->state == 3)
			this->state = 1;
		else
			this->state = this->state + 1;
	}
	else if (event.key.code == sf::Keyboard::Up) {
		if (this->state == 1)
			this->state = 3;
		else
			this->state = this->state - 1;
	}
	this->drawTitles();
	if (event.key.code == sf::Keyboard::Return)
		this->handleReturnState();
}

/**
* @brief initalise la couleur d'affichage des options
*
*/

void	MenuControllers::initColors()
{
	this->blue.r = 1;
	this->blue.g = 205;
	this->blue.b = 254;
	this->light.r = 255;
	this->light.g = 251;
	this->light.b = 150;
}

/**
* @brief getter de la variable texte play
*
* @return sf::Text play
*/

sf::Text	MenuControllers::getPlay() const
{
	return this->play;
}

/**
* @brief getter de la variable texte options
*
* @return sf::Text options
*/

sf::Text	MenuControllers::getOptions() const
{
	return this->options;
}

/**
* @brief getter de la variable texte exit
*
* @return sf::Text exit
*/

sf::Text	MenuControllers::getExit() const
{
	return this->exit;
}

/**
* @brief getter de l'état en cours
*
* @return int state
*/

int	MenuControllers::getState() const
{
	return this->state;
}