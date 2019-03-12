/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

/**
* @file Tile.cpp
* @brief méthodes qui gèrent le contenu d'une case
* @author lmaignan et mgayaud
*
* Fichier contenant les méthodes qui gèrent le contenu d'une case
*
*/

#include "Tile.hpp"

/**
* @brief Construct a new Tile:: Tile object
*
*/

Tile::Tile()
{
}

/**
* @brief Destroy the Tile:: Tile object
*
*/

Tile::~Tile()
{
}

/**
* @brief getter de la position x de la case
*
* @return la position x
*/

int	Tile::getPosx() const
{
	return this->position.x;
}

/**
* @brief getter de la position y de la case
*
* @return la position y
*/

int	Tile::getPosy() const
{
	return this->position.y;
}

/**
* @brief getter d'une pierre de la case
*
* @return le numéro de la pierre
*/

int	Tile::getStone(int i) const
{
	return this->stones[i];
}

/**
* @brief getter de la nourriture de la case
*
* @return le numéro de la nourriture
*/

int	Tile::getFood() const
{
	return this->food;
}

/**
* @brief initialise une case et son contenu en fonction des infoormations
* envoyées par le serveur
*
* @param iaInfos commande envoyée par le serveur
*/

void	Tile::initTile(const std::vector<std::string> iaInfos)
{
	this->position.x = std::stoi(iaInfos[1]);
	this->position.y = std::stoi(iaInfos[2]);
	this->food = std::stoi(iaInfos[3]);
	this->stones[0] = std::stoi(iaInfos[4]);
	this->stones[1] = std::stoi(iaInfos[5]);
	this->stones[2] = std::stoi(iaInfos[6]);
	this->stones[3] = std::stoi(iaInfos[7]);
	this->stones[4] = std::stoi(iaInfos[8]);
	this->stones[5] = std::stoi(iaInfos[9]);
}