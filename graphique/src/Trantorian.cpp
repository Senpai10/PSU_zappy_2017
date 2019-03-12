/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

/**
* \file Trantorian.cpp
* \brief Fichier contenant les methodes de la classe Trantorian
* \author lmaignan et mgayaud
*
* Fichier contenant les methodes de la classe Trantorian
*
*/

#include "Trantorian.hpp"

/**
* \brief Constructeur de la classe trantorian
*
* \param id Id du nouveau joueur
* \param position Positions du nouveau joueur
* \param orientation Orientation du nouveau joueur
*/
Trantorian::Trantorian(int id, sf::Vector2f position, int orientation)
{
	this->id = id;
	this->position = position;
	this->orientation = orientation;
	this->alive = true;
	this->movePattern = 0;
	this->moving = false;
	this->it = 0.0f;
	this->queueIt = 0;
	this->picInfos.x = 0;
	this->picInfos.y = 0;
	this->picInfos.z = 0;
}

/**
* \brief Destructeur de la classe trantorian
*
*/
Trantorian::~Trantorian()
{

}

/**
* \brief Getter de l'identifiant
*
* \return Retourne l'identifiant
*/
int Trantorian::getId() const
{
	return this->id;
}

/**
* \brief Setter de positions
*
* \return Retourne l'identifiant
*/
void Trantorian::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

/**
* \brief Setter du booléen moving
*
* \param moving Booéen moving pour savoir si le joueur bouge
*/
void Trantorian::setMoving(bool moving)
{
	this->moving = moving;
}

/**
* \brief Setter de la scale
*
* \param squareScale scale d'une case
*/
void Trantorian::setScale(sf::Vector2f squareScale)
{
	this->scale = squareScale;
}

/**
* \brief Setter de l'orientation
*
* \param orientation Orientation du joueur
*/
void Trantorian::setOrientation(int orientation)
{
	if (orientation == 1) {
		this->orientation = 1;
		this->turnUp();
	}
	if (orientation == 2) {
		this->orientation = 2;
		this->turnRight();
	}
	if (orientation == 3) {
		this->orientation = 3;
		this->turnDown();
	}
	if (orientation == 4) {
		this->orientation = 4;
		this->turnLeft();
	}
}

/**
* \brief Getter du bool moving
*
* \return le bool moving
*/
bool Trantorian::getMoving() const
{
	return this->moving;
}

/**
* \brief Setter de l'itérateur
*
* \param it itérateur
*/
void Trantorian::setIt(float it)
{
	this->it = it;
}

/**
* \brief Getter de l'itérateur
*
* \return Retourne l'itérateur
*/
float Trantorian::getIt() const
{
	return this->it;
}

/**
* \brief Méthode d'initalisation du joueur
*
* \param level niveau du joueur
* \param team team du joueur
*/
void Trantorian::initTrantorianInfo(int level, std::string team)
{
	this->level = level;
	this->team = team;
}

/**
* \brief Getter des positions
*
* \return Retourne la position
*/
sf::Vector2f Trantorian::getPosition() const
{
	return this->position;
}

/**
* \brief Getter de l'orientation
*
* \return Retourne l'orientation
*/
int Trantorian::getOrientation() const
{
	return this->orientation;
}

/**
* \brief Méthode d'initalisation des positions
*
*/
void Trantorian::initPosition()
{
	if (this->orientation == 1)
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 3 - 2, 0, this->textureSize.x
			, this->textureSize.y));
	if (this->orientation == 2)
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			- 7, -5, this->textureSize.x / 1.05
			, this->textureSize.y));
	if (this->orientation == 3)
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 2 - 9, 0, this->textureSize.x
			, this->textureSize.y));
	if (this->orientation == 4)
		this->sprite.setTextureRect(sf::IntRect(-5, -5
			, this->textureSize.x, this->textureSize.y));
}

/**
* \brief Initialisation de l'incantation
*
*/
bool Trantorian::initPic()
{
	if (!this->picTexture.loadFromFile("./ressources/game/aura.png"))
		return false;
	this->picSprite.setTexture(this->picTexture);
	this->picTSize = this->picTexture.getSize();
	this->picTSize.x /= 12;
	this->picTSize.y /= 12;
	this->picSprite.setTextureRect(sf::IntRect(this->picTSize.x * 3 - 48
		, this->picTSize.y, this->picTSize.x, this->picTSize.y));
	this->picSprite.setScale(this->scale.x * 2, this->scale.y * 2);
	return true;
}

/**
* \brief initialise la texture, la scale et la position du joueur
*
* \return Retourne false si un problème arrive dans le chargement de ressource
*/
bool Trantorian::initTrantorianTexture()
{
	if (!this->texture.loadFromFile("./ressources/game/trantorian_sprites1.png"))
		return false;
	if (!this->texture2.loadFromFile("./ressources/game/trantorian_sprites12.png"))
		return false;
	this->sprite.setTexture(this->texture);
	this->textureSize = this->texture.getSize();
	this->textureSize.x /= 4;
	this->textureSize.y /= 3;
	this->initPosition();
	this->sprite.setPosition(this->position.x * (200.0 * this->scale.x)
		+ ((200.0 * this->scale.x) / 4)
		, this->position.y * (200.0 * this->scale.y)
		+ ((200.0 * this->scale.y) / 4));
	this->sprite.setScale(this->scale.x + (this->scale.x / 12)
		, this->scale.y  + (this->scale.y / 12));
	if (this->initPic() == false)
		return false;
	return true;
}

/**
* \brief Getter du sprite du joueur
*
* \return le sprite du joueur
*/
sf::Sprite Trantorian::getSprite() const
{
	return this->sprite;
}

/**
* \brief Tourne l'orientation du joueur vers le haut
*
*/
void Trantorian::turnUp()
{
	this->sprite.setTextureRect(sf::IntRect(this->textureSize.x * 3 - 2, 0
		, this->textureSize.x, this->textureSize.y));
}

/**
* \brief Tourne l'orientation du joueur vers le bas
*
*/
void Trantorian::turnDown()
{
	this->sprite.setTextureRect(sf::IntRect(this->textureSize.x * 2 - 9, 0
		, this->textureSize.x, this->textureSize.y));
}

/**
* \brief Tourne l'orientation du joueur vers la droite
*
*/
void Trantorian::turnRight()
{
	this->sprite.setTextureRect(sf::IntRect(this->textureSize.x - 7, -5
		, this->textureSize.x / 1.05, this->textureSize.y));
}

/**
* \brief Tourne l'orientation du joueur vers la gauche
*
*/
void Trantorian::turnLeft()
{
	this->sprite.setTextureRect(sf::IntRect(-5, -5
		, this->textureSize.x, this->textureSize.y));
}

/**
* \brief Avance le joueur vers le haut
*
*/
void Trantorian::moveUp()
{
	if (this->movePattern < 25
		|| (this->movePattern > 50 && this->movePattern < 75))
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 3 - 2, 0, this->textureSize.x
			, this->textureSize.y));
	else if (this->movePattern > 25 && this->movePattern < 50)
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 3 - 12, this->textureSize.y, this->textureSize.x
			, this->textureSize.y));
	else {
		this->sprite.setTexture(this->texture);
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 2 - 14, this->textureSize.y, this->textureSize.x
			, this->textureSize.y));
	}
	this->sprite.move(0.0f, -2.0f);
	this->movePattern += 2;
	if (this->movePattern >= 100)
		this->movePattern = 0;
}

/**
* \brief Avance le joueur vers le bas
*
*/
void Trantorian::moveDown()
{
	if (this->movePattern < 25
		|| (this->movePattern > 50 && this->movePattern < 75))
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 2 - 9, 0, this->textureSize.x
			, this->textureSize.y));
	else if (this->movePattern > 25 && this->movePattern < 50) {
		this->sprite.setTexture(this->texture2);
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			+ 10, this->textureSize.y * 2 - 7, this->textureSize.x
			, this->textureSize.y));
	} else {
		this->sprite.setTextureRect(sf::IntRect(2
			, this->textureSize.y * 2 - 5, this->textureSize.x
			, this->textureSize.y));
	}
	this->sprite.move(0.0f, 2.0f);
	this->movePattern += 2;
	if (this->movePattern >= 100)
		this->movePattern = 0;
}

/**
* \brief Avance le joueur vers la droite
*
*/
void Trantorian::moveRight()
{
	if (this->movePattern < 25
		|| (this->movePattern > 50 && this->movePattern < 75))
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			- 7, -5, this->textureSize.x / 1.05
			, this->textureSize.y));
	else if (this->movePattern > 25 && this->movePattern < 50)
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 2 + 12, this->textureSize.y * 2 + 5
			, this->textureSize.x / 1.05, this->textureSize.y));
	else {
		this->sprite.setTextureRect(sf::IntRect(-5
			, this->textureSize.y - 7, this->textureSize.x
			, this->textureSize.y));
	}
	this->sprite.move(2.0f, 0.0f);
	this->movePattern += 2;
	if (this->movePattern >= 100)
		this->movePattern = 0;
}

/**
* \brief Avance le joueur vers la gauche
*
*/
void Trantorian::moveLeft()
{
	if (this->movePattern < 25
		|| (this->movePattern > 50 && this->movePattern < 75))
		this->sprite.setTextureRect(sf::IntRect(-5, -5
			, this->textureSize.x, this->textureSize.y));
	else if (this->movePattern > 25 && this->movePattern < 50)
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			- 9, this->textureSize.y - 7
			, this->textureSize.x / 1.08, this->textureSize.y));
	else {
		this->sprite.setTextureRect(sf::IntRect(this->textureSize.x
			* 3 + 10, this->textureSize.y * 2 + 5
			, this->textureSize.x / 1.05, this->textureSize.y));
	}
	this->sprite.move(-2.0f, 0.0f);
	this->movePattern += 2;
	if (this->movePattern >= 100)
		this->movePattern = 0;
}

/**
* \brief Ejecte le joueur sur le côté
*
* \param distance Distance d'éjection
*/
void Trantorian::getEjected(sf::Vector2f distance)
{
	int i = 0;

	while (i < distance.x) {
		this->sprite.move(-2.0f, 0.0f);
		i++;
	}
	this->position.x -= 1.0f;
}

/**
* \brief Ajoute une commande a la queue de commande
*
* \param infos Commande à ajouter
*/
void Trantorian::addCommand(std::string infos)
{
	this->commandQueue.push_back(infos);
}

/**
* \brief Getter de la taille de la queue de commande
*
* \return la taille de la queue de commande
*/
int Trantorian::getQueueSize() const
{
	return this->commandQueue.size();
}

/**
* \brief Getter de la commande
*
* \param id Id de la commande dans la queue de commande
* \return la commande à l'indexe id
*/
std::string Trantorian::getCommand(int id) const
{
	return this->commandQueue[id];
}

/**
* \brief Getter de la variable queueIt pour savoir si 
*  la commande doit être ajouté
*
* \return queueIt
*/
int Trantorian::getQueueIt() const
{
	return this->queueIt;
}

/**
* \brief Setter de queueIt
*
* \return param int pour savoir si on l'ajoute à la queue de commande
*/
void Trantorian::setQueueIt(int i)
{
	this->queueIt = i;
}

/**
* \brief Méthode pour que le joueur passe d'un côté à l'autre de la map
*
* \param o int pour savoir vers ou traverser
* \param distance distance à traverser
* \param mapSize Tailel de la map
*/
void Trantorian::crossMap(int o, sf::Vector2f distance, sf::Vector2i mapSize)
{
	int i = 0;

	if (o == 1) {
		while (i < (distance.y * (mapSize.y - 1))) {
			this->sprite.move(0.0f, 2.0f);
			i++;
		}
		this->position.y = mapSize.y - 1;
	}
	if (o == 2) {
		while (i < (distance.x * (mapSize.x - 1))) {
			this->sprite.move(-2.0f, 0.0f);
			i++;
		}
		this->position.x = 0;
	}
}

/**
* \brief Méthode pour que le joueur passe d'un côté à l'autre de la map
*
* \param o int pour savoir vers ou traverser
* \param distance distance à traverser
* \param mapSize Tailel de la map
*/
void Trantorian::crossMap2(int o, sf::Vector2f distance, sf::Vector2i mapSize)
{
	int i = 0;

	if (o == 3) {
		while (i < (distance.y * (mapSize.y - 1))) {
			this->sprite.move(0.0f, -2.0f);
			i++;
		}
		this->position.y = 0;
	}
	if (o == 4) {
		while (i < (distance.x * (mapSize.x - 1))) {
			this->sprite.move(2.0f, 0.0f);
			i++;
		}
		this->position.x = mapSize.x - 1;
	}
}

/**
* \brief Setter des informations de l'incantation
*
* \param x position x du joueur
* \param y position y du joueur
* \param state état de l'incantation
*/
void Trantorian::setPicInfos(int x, int y, int state)
{
	this->picInfos.x = x;
	this->picInfos.y = y;
	this->picInfos.z = state;
}

/**
* \brief Getter des informations de l'incantation
*
* \return return les informations de l'incantation
*/
sf::Vector3i Trantorian::getPicInfos() const
{
	return this->picInfos;
}

/**
* \brief Setter du niveau
*
* \param level niveau du joueur
*/
void Trantorian::setLevel(int level)
{
	this->level = level;
}

/**
* \brief getter du sprite d'incantation
*
* \return le sprite d'incantation
*/
sf::Sprite Trantorian::getPicSprite() const
{
	return this->picSprite;
}

/**
* \brief Initialise la position de l'incantation
*
*/
void Trantorian::picPos()
{
	this->picSprite.setPosition(this->picInfos.x
		* (200.0 * this->scale.x)
		, this->picInfos.y * (200.0 * this->scale.y));
}

/**
* \brief Anime l'aura d'incantation
*
*/
void Trantorian::moveAura()
{
	if (this->movePattern < 25) {
		picSprite.setTextureRect(sf::IntRect(-10, picTSize.y
			, picTSize.x, picTSize.y));
	}
	if (this->movePattern > 25 && this->movePattern < 50) {
		picSprite.setTextureRect(sf::IntRect(picTSize.x - 22
			, picTSize.y, picTSize.x, picTSize.y));
	}
	if (this->movePattern > 50 && this->movePattern < 75) {
		picSprite.setTextureRect(sf::IntRect(picTSize.x * 2 - 32
			, picTSize.y, picTSize.x, picTSize.y));
	}
	if (this->movePattern > 75) {
		picSprite.setTextureRect(sf::IntRect(picTSize.x * 3 - 48
			, picTSize.y, picTSize.x, picTSize.y));
	}
	this->movePattern += 4;
	if (this->movePattern >= 100)
		this->movePattern = 0;
}

/**
* \brief Cherche le joueur en train d'incanter
*
* \param picPos la position du joueur qui incante
* \return 1 Si il est trouvé, sinon 0
*/
int Trantorian::findIncPlayer(sf::Vector2i picPos)
{
	if (this->position.x == picPos.x && this->position.y == picPos.y) {
		if (this->picInfos.z == 1) {
			this->picInfos.z = 0;
			return 1;
		}
	}
	return 0;
}