/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#include "SFML/Graphics.hpp"
#include "iostream"

#pragma once

class Tile {
public:
	Tile();
	~Tile();
	int getPosx() const;
	int getPosy() const;
	int getFood() const;
	int getStone(int) const;
	void initTile(const std::vector<std::string> iaInfos);
private:
	int food;
	int stones[6];
	sf::Vector2i position;
};