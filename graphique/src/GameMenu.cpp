/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

/**
* @file GameMenu.cpp
* @brief méthodes qui lancent le menu principal
* @author lmaignan et mgayaud
*
* Fichier contenant les méthodes de la classe GameMenu qui affichent
* l'écran d'accueil
*
*/

#include "../include/ZappyGraphic.hpp"

/**
* @brief Construct a new Game Menu:: Game Menu object
*
*/

GameMenu::GameMenu() : window(sf::VideoMode(1920, 1080), "Zappy"), controll()
{
	this->fileNameIntro = "./ressources/startMenu/img00";
	this->fileNameLoop = "./ressources/loopMenu/img0";
	this->titleTexture.loadFromFile("./ressources/loopMenu/title.png");
	this->titleSprite.setTexture(this->titleTexture);
	this->menuMusic.openFromFile("./ressources/music/MenuMusic.ogg");
	this->menuMusic.setLoop(true);
	this->wipTexture.loadFromFile("./ressources/loopMenu/wip.png");
	this->wipSprite.setTexture(this->wipTexture);
	this->wipSprite.setScale(1.0f, 0.95f);
}

/**
* @brief Destroy the Game Menu:: Game Menu object
*
*/

GameMenu::~GameMenu()
{

}

/**
* @brief ferme la fenêtre si l'utilisateur clique sur la croix
*
*/

void	GameMenu::handleClosure()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

/**
* @brief affiche l'introduction
*
* @param str fichier contenant la texture
* @return -1 en cas d'erreur sinon 0
*/

int	GameMenu::loadAndDrawIntro(const std::string str)
{
	if (!this->backgroundTexture.loadFromFile(str))
			return -1;
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->window.clear();
	this->window.draw(this->backgroundSprite);
	this->window.display();
	return 0;
}

/**
* @brief enchaîne les textures à afficher pour l'introduction
*
* @return -1 en cas d'erreur sinon 0
*/

int GameMenu::displayIntro()
{
	int i = 14;
	std::string str;

	this->menuMusic.play();
	while (i != 34) {
		str = str + this->fileNameIntro + std::to_string(i) + ".jpg";
		if (!this->backgroundTexture.loadFromFile(str))
			return -1;
		if (this->loadAndDrawIntro(str) == -1)
			return -1;
		this->handleClosure();
		i++;
		str = "";
		usleep(10000);
	}
	return 0;
}

/**
* @brief permet de gérer l'entrée utilisateur sur le menu principal
*
* @return 0 en cas de succès
*/

int	GameMenu::handleMenuAction()
{
	sf::Event event;

	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed)
			this->controll.handleState(event);
		if (event.type == sf::Event::Closed)
			window.close();
	}
	if (this->controll.getState() == 6){
		this->menuMusic.stop();
		this->window.close();
		exit(0);
	}
	return 0;
}

/**
* @brief actualise l'affichage du menu principal
*
* @param str fichier qui contient l'image de fond
* @return -1 en cas d'erreur sinon 0
*/

int	GameMenu::handleLoop(const std::string str)
{
	this->window.clear();
	if (this->controll.getState() == 5) {
		this->window.draw(this->wipSprite);
	}
	else {
		if (!this->backgroundTexture.loadFromFile(str))
				return -1;
		this->backgroundSprite.setTexture(this->backgroundTexture);
		this->window.draw(this->backgroundSprite);
		this->titleSprite.setPosition(sf::Vector2f(580, 0));
		this->window.draw(this->titleSprite);
		this->window.draw(this->controll.getPlay());
		this->window.draw(this->controll.getOptions());
		this->window.draw(this->controll.getExit());
	}
	if (this->handleMenuAction() == -1)
		return -1;
	this->window.display();
	return 0;
}

/**
* @brief initialise et lance la boucle d'affichage du menu
*
* @return -1 en cas d'erreur sinon 0
*/

int GameMenu::displayLoop()
{
	int i = 34;
	std::string str;

	while (this->window.isOpen() && this->controll.getState() != 4) {
		if (i < 100) {
			str = str + this->fileNameLoop + "0"
			+ std::to_string(i) + ".jpg";
		} else
			str = str + this->fileNameLoop
			+ std::to_string(i) + ".jpg";
		if (this->handleLoop(str) == -1)
			return -1;
		i++;
		if (i == 151)
			i = 34;
		str = "";
		usleep(5000);
	}
	this->menuMusic.stop();
	return 0;
}

/**
* @brief getter du controle des entrées utilisateur
*
* @return objet MenuControllers
*/

MenuControllers	GameMenu::getControll() const
{
	return this->controll;
}

/**
* @brief getter de la fenêtre d'affichage
*
* @return objet sf::RenderWindow
*/

sf::RenderWindow& GameMenu::getWindow()
{
	return this->window;
}