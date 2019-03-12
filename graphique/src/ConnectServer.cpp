/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

/**
* @file ConnectServer.cpp
* @brief méthodes qui lancent la connexion entre le client graphique et
* le serveur
* @author lmaignan et mgayaud
*
* Fichier contenant les méthodes de la classe ConnectServer qui affichent
* l'écran de connexion et effectuent la connexion au seveur
*
*/

#include "../include/ZappyGraphic.hpp"

/**
* @brief Construct a new Connect Server:: Connect Server object
*
* @param mainWindow object
*/

ConnectServer::ConnectServer(sf::RenderWindow &mainWindow) : window(mainWindow)
{
	this->font.loadFromFile("./ressources/font/retromonowide.ttf");
	this->connectMusic.openFromFile("./ressources/music/loginMusic.ogg");
	this->vaporBlue.r = 1;
	this->vaporBlue.g = 205;
	this->vaporBlue.b = 254;
	this->backgroundTexture.loadFromFile("./ressources/login/bg.png");
	this->frameTexture.loadFromFile("./ressources/login/frame.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.scale(sf::Vector2f(1.3f, 1.1f));
	this->frameSprite.setTexture(this->frameTexture);
	this->frameSprite.setPosition(400, 0);
	this->hostText.setFont(font);
	this->hostText.setFillColor(vaporBlue);
	this->hostText.setPosition(740, 350);
	this->hostText.setCharacterSize(55);
	this->portText.setFont(font);
	this->portText.setFillColor(vaporBlue);
	this->portText.setPosition(740, 450);
	this->portText.setCharacterSize(55);
	this->connected = 0;
}

/**
* @brief Destroy the Connect Server:: Connect Server object
*
*/

ConnectServer::~ConnectServer()
{

}

/**
* @brief vérifie et exécute les actions de l'utilisateur
*
* @return 0 en cas de succès
*/

int	ConnectServer::manageEvent()
{
	sf::Event event;

	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed
			&& event.mouseButton.button == sf::Mouse::Left)
			this->handleMouseAction(event);
		if (event.type == sf::Event::TextEntered)
			this->addToString(event);
	}
	return 0;
}

/**
* @brief affiche la fenêtre de connexion
*
* @return 0 en cas de succès
*/

int	ConnectServer::displayBackground()
{
	this->window.clear();
	this->window.draw(this->backgroundSprite);
	this->window.draw(this->frameSprite);
	this->window.draw(this->portText);
	this->window.draw(this->hostText);
	this->window.display();
	return 0;
}

/**
* @brief enclenche la connexion au serveur
*
* @return 0 en cas de succès
*/

int	ConnectServer::startConnect()
{
	char buff [9] = "GRAPH 1\n";
	this->connectMusic.setLoop(true);
	this->connectMusic.play();
	while (this->window.isOpen() && this->connected == 0) {
		this->manageEvent();
		this->displayBackground();
		usleep(10000);
	}
	if (this->socket.send(buff, 9) != sf::Socket::Done)
		return -1;
	this->connectMusic.stop();
	return 0;
}

/**
* @brief essai d'une connexion au serveur
*
*/

void	ConnectServer::tryConnect()
{
	if (this->portString.length() > 3 
		&& std::all_of(this->portString.begin()
			, this->portString.end(), ::isdigit) == true)
		this->status = this->socket.connect(this->hostString
			, std::stoi(this->portString));
	if (this->status != sf::Socket::Done) {
		this->hostString = "";
		this->portString = "";
		this->hostText.setString("");
		this->portText.setString("");
	}
	if (this->socket.getRemotePort() != 0)
		this->connected = 1;
	this->clickState = 0;
}

/**
* @brief permet de stocker l'ip ou le port en fonction de l'endroit cliqué
*
* @param event texte entré par l'utilisateur
* @return 0 en cas de succès
*/

int	ConnectServer::addToString(sf::Event event)
{
	if (event.text.unicode == '\b') {
		this->delToString();
		return 0;
	}
	if (this->clickState == 1) {
		if (this->hostString.length() <= 11) {
			this->hostString
			+= static_cast<char>(event.text.unicode);
			this->hostText.setString(this->hostString);
		}
	}
	if (this->clickState == 2) {
		if (this->portString.length() <= 5) {
			this->portString
			+= static_cast<char>(event.text.unicode);
			this->portText.setString(this->portString);
		}
	}
	return 0;
}

/**
* @brief permet à l'utilisateur de corriger ce qu'il a entré
*
*/

void	ConnectServer::delToString()
{
	if (this->clickState == 1) {
		if (this->hostString.length() >= 1) {
			this->hostString.erase(this->hostString.size()
				- 1, 1);
			this->hostText.setString(this->hostString);
		}
	}
	if (this->clickState == 2) {
		if (this->portString.length() >= 1) {
			this->portString.erase(this->portString.size()
				- 1, 1);
			this->portText.setString(this->portString);
		}
	}
}

/**
* @brief lance la méthode adéquate en fonction du clic de l'utilisateur
*
* @param event permet de savoir à quel endroit de la fenêtre l'utilisateur
* a cliqué
* @return 0 en cas de succès
*/

int	ConnectServer::handleMouseAction(sf::Event event)
{
	if (event.mouseButton.x >= 730 && event.mouseButton.x <= 1390) {
		if (event.mouseButton.y >= 330 && event.mouseButton.y
		<= 420)
			this->clickState = 1;
		if (event.mouseButton.y >= 440 && event.mouseButton.y
		<= 520)
			this->clickState = 2;
	}
	if (event.mouseButton.x >= 1200 && event.mouseButton.x <= 1435
		&& event.mouseButton.y >= 560 && event.mouseButton.y <= 630)
		this->tryConnect();
	if (event.mouseButton.x < 730 && event.mouseButton.x > 1390
		&& event.mouseButton.y < 330 && event.mouseButton.y > 630)
		this->clickState = 0;
	return 0;
}

/**
* @brief getter de la socket
*
* @return la socket
*/

sf::TcpSocket&	ConnectServer::getSocket()
{
	return this->socket;
}

/**
* @brief setter du clickState
*
* @param Etat de clic
*/
void	ConnectServer::setClick(int state)
{
	this->clickState = state;
}

/**
* @brief setter du port ou de l'hote
*
* @param str Chaine à assigner
* @param nb Quelle chaine doit prendre str
*/
void	ConnectServer::setString(std::string str, int nb)
{
	if (nb == 0)
		this->portString = str;
	else
		this->hostString = str;
}

/**
* @brief getter des string
*
* @param nb Quelle string à renvoyer
* @return string à renvoyer
*/
std::string ConnectServer::getString(int nb) const
{
	if (nb == 0)
		return this->portString;
	else
		return this->hostString;
}