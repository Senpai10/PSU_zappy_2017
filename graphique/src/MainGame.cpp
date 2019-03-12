/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

/**
* @file MenuControllers.cpp
* @brief méthodes qui gèrent la totalité des aspects graphiques
* de la simulation
* @author lmaignan et mgayaud
*
* Fichier contenant les méthodes qui initialisent et synchronisent chaque
* aspect graphique de la simulation, en récupérant les instructions du serveur
*
*/

#include "../include/ZappyGraphic.hpp"

/**
* @brief Construct a new Main Game:: Main Game object
*
* @param mainWindow fenêtre d'affichage
* @param mainSocket socket qui permet de communiquer avec le serveur
*/

MainGame::MainGame(sf::RenderWindow &mainWindow, sf::TcpSocket &mainSocket)
: window(mainWindow), socket(mainSocket)
{
	this->squareTexture.loadFromFile("./ressources/mainGame/square.png");
	this->square.setTexture(this->squareTexture);
	this->view.reset(sf::FloatRect(0, 0 , 1920, 1080));
	this->socket.setBlocking(false);
	this->gameMusic.openFromFile("./ressources/music/GameMusic.ogg");
	this->gameMusic.setLoop(true);
}

/**
* @brief Destroy the Main Game:: Main Game object
*
*/

MainGame::~MainGame()
{
}

/**
* @brief initialise le tableau de pointeur sur méthodes des instructions
* du serveur
*
*/

void	MainGame::initTabs()
{
	this->functionTab[0] = &MainGame::handleMap;
	this->functionTab[1] = &MainGame::newTrantorian;
	this->functionTab[2] = &MainGame::initMovement;
	this->functionTab[3] = &MainGame::manageTile;
	this->functionTab[4] = &MainGame::expulseTrantorian;
	this->functionTab[5] = &MainGame::startIncantation;
	this->functionTab[6] = &MainGame::endIncantation;
	this->tabCommand[0] = new std::string("msz");
	this->tabCommand[1] = new std::string("pnw");
	this->tabCommand[2] = new std::string("ppo");
	this->tabCommand[3] = new std::string("bct");
	this->tabCommand[4] = new std::string("pex");
	this->tabCommand[5] = new std::string("pic");
	this->tabCommand[6] = new std::string("pie");
}

/**
* @brief initialise l'affichage de la nourriture
*
*/

void MainGame::initFood()
{
	this->foodTexture.loadFromFile("./ressources/game/food.png");
	this->ressourcesSprite[6].setTexture(this->foodTexture);
}

/**
* @brief initialise l'affichage des gemmes
*
*/

void MainGame::initRessources()
{
	this->ressourcesTexture.loadFromFile("./ressources/game/gems.png");
	this->textureSize = this->ressourcesTexture.getSize();
	this->textureSize.x /= 6;
	this->textureSize.y /= 3;

	for (int i = 0; i != 6; i++)
		this->ressourcesSprite[i].setTexture(this->ressourcesTexture);
	this->ressourcesSprite[0].setTextureRect(sf::IntRect(textureSize.x * 2
		, textureSize.y, textureSize.x, textureSize.y));
	this->ressourcesSprite[1].setTextureRect(sf::IntRect(textureSize.x * 4
		, textureSize.y * 2, textureSize.x, textureSize.y));
	this->ressourcesSprite[2].setTextureRect(sf::IntRect(textureSize.x * 2
		, textureSize.y * 2, textureSize.x, textureSize.y));
	this->ressourcesSprite[3].setTextureRect(sf::IntRect(textureSize.x * 3
		, textureSize.y, textureSize.x, textureSize.y));
	this->ressourcesSprite[4].setTextureRect(sf::IntRect(0, textureSize.y
		, textureSize.x, textureSize.y));
	this->ressourcesSprite[5].setTextureRect(sf::IntRect(textureSize.x * 5
		, textureSize.y, textureSize.x, textureSize.y));
	this->initFood();
}

/**
* @brief initialise la map en fonction de la taille envoyée par le serveur
*
* @param command taille de la map envoyée par le serveur
* @return 0 en cas de succès
*/

int	MainGame::handleMap(const std::string command)
{
	char *charCommand = new char[command.length() + 1];
	strcpy(charCommand, command.c_str());
	strtok(charCommand, " ");
	sf::Vector2f newScale;

	this->mapSize.x = atoi(strtok(NULL, " "));
	this->mapSize.y = atoi(strtok(NULL, " "));
	newScale.x = 1920.0 / (this->mapSize.x * 200);
	newScale.y = 1080.0 / (this->mapSize.y * 200);
	this->square.scale(newScale.x, newScale.y);
	this->scale = this->square.getScale();
	for (int x = 0; x != 6; x++)
		this->ressourcesSprite[x].setScale(this->scale.x
			- (this->scale.x / 1.9)
			, this->scale.y - (this->scale.y / 1.9));
	this->ressourcesSprite[6].setScale(this->scale.x - (scale.x / 5.0)
			, this->scale.y - (this->scale.y / 5.0));
	this->distance.x = (200.0f * newScale.x) / 2;
	this->distance.y = (200.0f * newScale.y) / 2;
	return 0;
}

/**
* @brief check si le serveur a envoyé une commande par la socket
*
* @return la commande envoyée par le serveur
*/

std::string	MainGame::getCommand()
{
	std::string command;
	std::size_t received;
	char buff[1];

	buff[0] = '\0';
	while (buff[0] != '\n') {
		if (socket.receive(buff, 1, received) != sf::Socket::Done)
			return "\0";
		buff[1] = '\0';
		command += std::string(buff);
	}
	return command;
}

/**
* @brief affiche les trantorians (ia) à l'écran
*
*/

void	MainGame::displayTrantorians()
{
	unsigned int i = 0;

	if (this->tList.size() > 0) {
		while (i != this->tList.size()) {
			this->window.draw(this->tList[i]->getSprite());
			i++;
		}
	}
}

/**
* @brief récupère et excécute la commande envoyée par le serveur
*
* @return -1 en cas d'erreur, 1 si aucune commande n'a été envoyéé
* ou 0 en cas de succès
*/

int	MainGame::handleCommands()
{
	std::string command = this->getCommand();
	if (command[0] == '\0')
		return 1;
	char *cutCommand = new char[command.length() + 1];
	strcpy(cutCommand, command.c_str());
	strtok(cutCommand, " ");

	std::cout << command << std::endl;
	for (int i = 0; i != 7; i++) {
		if (strcmp(this->tabCommand[i]->c_str(), cutCommand) == 0) {
			if ((this->*functionTab[i])(command) == -1)
				return -1;
			else
				return 0;
		}
	}
	return 0;
}

/**
* @brief récupère et exécute une commande qui a été placée en attente
*
* @param command la commande à exécuter
* @return -1 en cas d'erreur sinon 0
*/

int	MainGame::startWaitingCommand(const std::string command)
{
	char *cutCommand = new char[command.length() + 1];
	strcpy(cutCommand, command.c_str());
	strtok(cutCommand, " ");

	for (int i = 0; i != 7; i++) {
		if (strcmp(this->tabCommand[i]->c_str(), cutCommand) == 0) {
			if ((this->*functionTab[i])(command) == -1)
				return -1;
			else
				return 0;
		}
	}
	return 0;
}

/**
* @brief détermine si il y a une commande en attente et si elle
* peut être lancée
*
* @return -1 en cas d'erreur sinon 0
*/

int	MainGame::handleWaitingCommands()
{
	unsigned int i = 0;
	int tmpIt;

	while (i < tList.size()) {
		if (tList[i]->getMoving() == false
			&& tList[i]->getQueueIt()
			< tList[i]->getQueueSize()) {
			tmpIt = tList[i]->getQueueIt();
			tList[i]->setQueueIt(tList[i]->getQueueSize());
			if (startWaitingCommand(tList[i]->getCommand(
				tmpIt)) == -1)
				return -1;
			tList[i]->setQueueIt(tmpIt + 1);
		}
		i++;
	}
	return 0;
}

/**
* @brief permet de zoomer, dézoomer et de décplacer l'angle de la caméra
* sur la map
*
* @param event entrée utilisateur
*/

void	MainGame::handleZoom(const sf::Event event)
{
	sf::Vector2f size = this->view.getSize();
	if (event.key.code == sf::Keyboard::Z)
		this->view.move(0, -50);
	if (event.key.code == sf::Keyboard::S)
		this->view.move(0, 50);
	if (event.key.code == sf::Keyboard::Q)
		this->view.move(-50, 0);
	if (event.key.code == sf::Keyboard::D)
		this->view.move(50, 0);
	if (event.key.code == sf::Keyboard::Up) {
		this->view.setSize(size.x - (200 * this->scale.x)
			, size.y - (200 * this->scale.y));
	}
	if (event.key.code == sf::Keyboard::Down) {
		this->view.setSize(size.x + (200 * this->scale.x)
			, size.y + (200 * this->scale.y));
	}
}

/**
* @brief méthode qui gère les entrées utilisateur
* (zoom et fermeture de la fenêtre)
*
*/

void	MainGame::handleEvents()
{
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			this->handleZoom(event);
		}
	}
}

/**
* @brief affiche la map case par case
*
*/

void	MainGame::displayBackground()
{
	int i = 0;
	int x = 0;
	sf::Vector2f move = this->square.getScale();

	move.x = move.x * 200;
	move.y = move.y * 200;
	while (i != this->mapSize.y) {
		while (x != this->mapSize.x) {
			this->window.draw(this->square);
			this->square.move(move.x, 0);
			x++;
		}
		this->square.setPosition(0, (float)(move.y * (float)i));
		x = 0;
		i++;
	}
}

/**
* @brief initialise et affiche une gemme
*
* @param tile case sur laquelle afficher la gemme
* @param nb numéro du sprite de la gemme
* @param posx position x dans la case
* @param posy position y dans la case
*/

void	MainGame::setAndDraw(Tile *tile, int nb, float posx, float posy)
{
	this->ressourcesSprite[nb].setPosition(tile->getPosx()
		* (200 * this->scale.x) + posx
		, tile->getPosy() * (200 * this->scale.y) + posy);
	this->window.draw(this->ressourcesSprite[nb]);
}

/**
* @brief affiche une case et son contenu
*
* @param tile la case à afficher
*/

void	MainGame::drawTile(Tile *tile)
{
	if (tile->getStone(0) > 0)
		this->setAndDraw(tile, 0, 0.0, 0.0);
	if (tile->getStone(1) > 0)
		this->setAndDraw(tile, 1, (200 * this->scale.x) / 2.9, 0.0);
	if (tile->getStone(2) > 0)
		this->setAndDraw(tile, 2, (200 * this->scale.x) / 1.4, 0.0);
	if (tile->getStone(3) > 0)
		this->setAndDraw(tile, 3, (200 * this->scale.x) / 1.4
			, (200 * this->scale.y) / 1.4);
	if (tile->getStone(4) > 0)
		this->setAndDraw(tile, 4, (200 * this->scale.x) / 2.9
			, (200 * this->scale.y) / 1.4);
	if (tile->getStone(5) > 0)
		this->setAndDraw(tile, 5, 0, (200 * this->scale.y) / 1.4);
	if (tile->getFood() > 0)
		this->setAndDraw(tile, 6, this->scale.x
			, (200 * this->scale.y) / 2.9);
}

/**
* @brief vérifie si il y'a des animations d'incantation à
* lancer et les lance
*
*/

void MainGame::tryPic()
{
	sf::Vector3i picInfos;

	for (unsigned int i = 0; i < tList.size(); i++) {
		picInfos = tList[i]->getPicInfos();
		if (picInfos.z == 1) {
			this->tList[i]->picPos();
			this->tList[i]->moveAura();
			this->window.draw(tList[i]->getPicSprite());
		}
	}
}

/**
* @brief boucle qui va lancer l'affichage de toutes les cases
*
*/

void	MainGame::displayTilesContent()
{
	unsigned int i = 0;

	while (i != this->tiles.size()) {
		this->drawTile(this->tiles[i]);
		i++;
	}
}

/**
* @brief lance toutes les méthodes d'affichage (joueurs, map, ressources)
*
*/

void	MainGame::displayInfos()
{
	this->window.clear();
	this->window.setView(this->view);
	this->displayBackground();
	this->displayTilesContent();
	this->tryMove();
	this->tryPic();
	this->displayTrantorians();
	this->window.display();
}

/**
* @brief lance la simulation
*
* @return -1 en cas d'erreur sinon 0
*/

int	MainGame::startGame()
{
	this->initTabs();
	this->initRessources();
	this->gameMusic.play();

	while (this->window.isOpen()) {
		this->handleEvents();
		if (this->handleCommands() == -1)
			return -1;
		if (this->handleWaitingCommands() == -1)
			return -1;
		this->displayInfos();
		usleep(10000);
	}
	this->gameMusic.stop();
	return 0;
}

/**
* @brief découpe la commande en plusieurs strings
*
* @param infos commande envoyée par le serveur
* @return std::vector<std::string> vecteur contenant chaque argument
* de la commande sous forme de string
*/

std::vector<std::string> MainGame::getCommandInfos(const std::string infos)
{
	std::vector<std::string> iaInfos;
	std::string token;
	int i = 0;

	while (infos[i] != '\n') {
		if (infos[i] == ' ') {
			i++;
			iaInfos.push_back(token);
			token.clear();
		}
		token += infos[i];
		if (infos[i] != '\n')
			i++;
	}
	iaInfos.push_back(token);
	return iaInfos;
}

/**
* @brief initialise un nouveau trantorian
*
* @param infos informations complémentaires sur l'ia
* (position, niveau, etc...)
* @return -1 en cas d'erreur sinon 0
*/

int MainGame::newTrantorian(const std::string infos)
{
	std::vector<std::string> iaInfos = getCommandInfos(infos);
	sf::Vector2f position;
	Trantorian *titi;

	position.x = std::stof(iaInfos[2]);
	position.y = std::stof(iaInfos[3]);
	titi = new Trantorian(std::stoi(iaInfos[1])
		, position, std::stoi(iaInfos[4]));
	titi->initTrantorianInfo(std::stoi(iaInfos[5]), iaInfos[6]);
	titi->setScale(this->square.getScale());
	if (titi->initTrantorianTexture() == false)
		return -1;
	this->tList.push_back(titi);
	return 0;
}

/**
* @brief vérifie si la commande peut être exécutée et la place en file
* d'attente le cas échéant
*
* @param id identifiant du joueur concerné par la commande
* @param infos commande envoyée par le serveur
* @return int 1 si la commande est placée en file d'attente sinon 0
*/

int MainGame::organizeCommand(int id, const std::string infos)
{
	if (this->tList[id]->getMoving() == true
		|| this->tList[id]->getQueueIt()
		< this->tList[id]->getQueueSize()) {
		this->tList[id]->addCommand(infos);
		return 1;
	}
	return 0;
}

/**
* @brief replace à l'opposé un joueur qui sort de l'écran (suite)
*
* @param x nouvelle position x récupéré
* @param y nouvelle position y récupéré
* @param i id du joueur
* @return 1 si le joueur est sorti le l'écran sinon 0
*/

int MainGame::checkEdge2(float x, float y, int i)
{
	if (this->tList[i]->getOrientation() == 3) {
		if (y < pos.y) {
			this->tList[i]->crossMap2(3, distance, mapSize);
			return 1;
		}
	}
	if (this->tList[i]->getOrientation() == 4) {
		if (x > pos.x) {
			this->tList[i]->crossMap2(4, distance, mapSize);
			return 1;
		}
	}
	return 0;
}

/**
* @brief replace à l'opposé un joueur qui sort de l'écran
*
* @param x nouvelle position x récupéré
* @param y nouvelle position y récupéré
* @param i id du joueur
* @return 1 si le joueur est sorti le l'écran sinon 0
*/

int MainGame::checkEdge(float x, float y, int i)
{
	if (this->tList[i]->getOrientation() == 1) {
		if (y > pos.y) {
			this->tList[i]->crossMap(1, distance, mapSize);
			return 1;
		}
	}
	if (this->tList[i]->getOrientation() == 2) {
		if (x < pos.x) {
			this->tList[i]->crossMap(2, distance, mapSize);
			return 1;
		}
	}
	if (checkEdge2(x, y, i) == 1)
		return 1;
	return 0;
}

/**
* @brief initialise le début du déplacement d'un trantorian
*
* @param infos commande de déplacement envoyée par le serveur
* @return 0 en cas de succès
*/

int MainGame::initMovement(const std::string infos)
{
	std::vector<std::string> infosTab = getCommandInfos(infos);
	int i = 0;

	while (std::stoi(infosTab[1]) != this->tList[i]->getId())
		i++;
	if (organizeCommand(i, infos) == 1)
		return 0;
	pos = tList[i]->getPosition();
	this->tList[i]->setOrientation(std::stoi(infosTab[4]));
	if (checkEdge(std::stof(infosTab[2]), std::stof(infosTab[3]), i) == 1)
		return 0;
	if (pos.x != std::stof(infosTab[2])
		|| pos.y != std::stof(infosTab[3])) {
		this->tList[i]->setMoving(true);
		this->tList[i]->setPosition(std::stof(infosTab[2])
			, std::stof(infosTab[3]));
	}
	return 0;
}

/**
* @brief déplace de force un trantorian sur sa case de gauche
*
* @param infos commande d'expulsion envoyée par le serveur
* @return 0 en cas de succès
*/

int MainGame::expulseTrantorian(const std::string infos)
{
	std::vector<std::string> infosTab = getCommandInfos(infos);
	int i = 0;

	while (std::stoi(infosTab[1]) != this->tList[i]->getId())
		i++;
	if (organizeCommand(i, infos) == 1)
		return 0;
	this->tList[i]->getEjected(this->distance);
	return 0;
}

/**
* @brief déplace un trantorian d'une case vers le haut
*
* @param id identifiant du trantorian qui doit se déplacer
*/

void MainGame::moveUp(int id)
{
	if (this->tList[id]->getMoving() == true
		&& this->tList[id]->getIt() < this->distance.y) {
		this->tList[id]->setIt(this->tList[id]->getIt() + 1.00f);
		this->tList[id]->moveUp();
	} else {
		this->tList[id]->setIt(0.0f);
		this->tList[id]->setMoving(false);
		this->tList[id]->turnUp();
	}
}

/**
* @brief déplace un trantorian d'une case vers la droite
*
* @param id identifiant du trantorian qui doit se déplacer
*/

void MainGame::moveRight(int id)
{
	if (this->tList[id]->getMoving() == true
		&& this->tList[id]->getIt() < this->distance.x) {
		this->tList[id]->setIt(this->tList[id]->getIt() + 1.00f);
		this->tList[id]->moveRight();
	} else {
		this->tList[id]->setIt(0.0f);
		this->tList[id]->setMoving(false);
		this->tList[id]->turnRight();
	}
}

/**
* @brief déplace un trantorian d'une case vers le bas
*
* @param id identifiant du trantorian qui doit se déplacer
*/

void MainGame::moveDown(int id)
{
	if (this->tList[id]->getMoving() == true
		&& this->tList[id]->getIt() < this->distance.y) {
		this->tList[id]->setIt(this->tList[id]->getIt() + 1.00f);
		this->tList[id]->moveDown();
	} else {
		this->tList[id]->setIt(0.0f);
		this->tList[id]->setMoving(false);
		this->tList[id]->turnDown();
	}
}

/**
* @brief déplace un trantorian d'une case vers la gauche
*
* @param id identifiant du trantorian qui doit se déplacer
*/

void MainGame::moveLeft(int id)
{
	if (this->tList[id]->getMoving() == true
		&& this->tList[id]->getIt() < this->distance.x) {
		this->tList[id]->setIt(this->tList[id]->getIt() + 1.00f);
		this->tList[id]->moveLeft();
	} else {
		this->tList[id]->setIt(0.0f);
		this->tList[id]->setMoving(false);
		this->tList[id]->turnLeft();
	}
}

/**
* @brief appelle la bonne fonction de déplacement du trantorian en fonction
* de son orientation
*
* @param id identifiant du trantorian qui doit se déplacer
*/

void MainGame::moveTrantorian(int id)
{
	if (this->tList[id]->getOrientation() == 1)
		this->moveUp(id);
	if (this->tList[id]->getOrientation() == 2)
		this->moveRight(id);
	if (this->tList[id]->getOrientation() == 3)
		this->moveDown(id);
	if (this->tList[id]->getOrientation() == 4)
		this->moveLeft(id);
}

/**
* @brief lance le mouvement des trantorians qui doivent se déplacer
*
*/

void MainGame::tryMove()
{
	unsigned int i = 0;

	while (i < this->tList.size()) {
		if (this->tList[i]->getMoving() == true)
			this->moveTrantorian(i);
		i++;
	}
}

/**
* @brief vérifie si une tile (case de la map) a été initialisée ou pas
*
* @param x position x de la tile
* @param y position y de la tile
* @return 1 si la tile existe sinon 0
*/

int	MainGame::tileExist(int x, int y)
{
	unsigned int i = 0;

	while (i != this->tiles.size()) {
		if (this->tiles[i]->getPosx() == x
			&& this->tiles[i]->getPosy() == y)
			return 1;
		i++;
	}
	return 0;
}

/**
* @brief met à jour les infos d'une tile
*
* @param iaInfos commande découpée envoyée par le serveur
*/

void	MainGame::updateTile(const std::vector<std::string> iaInfos)
{
	unsigned int i = 0;

	while (i != this->tiles.size()) {
		if (this->tiles[i]->getPosx() == std::stoi(iaInfos[1])
			&& this->tiles[i]->getPosy() == std::stoi(iaInfos[2]))
			this->tiles[i]->initTile(iaInfos);
		i++;
	}
}

/**
* @brief met à jour une tile ou l'initialise si elle n'existe pas déjà
*
* @param infos commande envoyée par le serveur
* @return 0 en cas de succès
*/

int	MainGame::manageTile(const std::string infos)
{
	std::vector<std::string> iaInfos = getCommandInfos(infos);
	Tile *newTile = new(Tile);

	if (this->tileExist(std::stoi(iaInfos[1])
		, std::stoi(iaInfos[2])) == 1)
		this->updateTile(iaInfos);
	else {
		newTile->initTile(iaInfos);
		this->tiles.push_back(newTile);
	}
	return 0;
}

/**
* @brief initialise le début d'une incantation
*
* @param infos commande envoyée par le serveur contenant les détails
* de l'incantation
* @return 0 en cas de succès
*/

int MainGame::startIncantation(std::string infos)
{
	std::vector<std::string> infosTab = getCommandInfos(infos);
	unsigned int i = 0;

	while (tList[i]->getId() != std::stoi(infosTab[4])) {
		i++;
	}
	tList[i]->setPicInfos(std::stoi(infosTab[1])
		, std::stoi(infosTab[2]), 1);
	i = 0;
	for (unsigned int it = 4; it < infosTab.size(); it++) {
		while (tList[i]->getId() != std::stoi(infosTab[it])) {
			i++;
		}
		tList[i]->setLevel(std::stoi(infosTab[3]));
		i = 0;
	}
	return 0;
}

/**
* @brief termine une incantation en cours
*
* @param infos commande envoyée par le serveur
* @return 0 en cas de succès
*/

int MainGame::endIncantation(const std::string infos)
{
	std::vector<std::string> infosTab = getCommandInfos(infos);
	sf::Vector2i picPos;
	unsigned int i = 0;

	picPos.x = std::stoi(infosTab[1]);
	picPos.y = std::stoi(infosTab[2]);
	while (i < tList.size()) {
		if (tList[i]->findIncPlayer(picPos) == 1)
			break;
		i++;
	}
	return 0;
}