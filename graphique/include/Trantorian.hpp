/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Trantorian
{
public:
	Trantorian(int id, sf::Vector2f position, int orientation);
	void initTrantorianInfo(int level, std::string team);
	~Trantorian();
	void initPosition();
	bool initTrantorianTexture();
	sf::Sprite getSprite() const;
	void turnUp();
	void turnDown();
	void turnRight();
	void turnLeft();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void getEjected(sf::Vector2f distance);
	void startIncantation();
	void setMoving(bool moving);
	bool getMoving() const;
	void setScale(sf::Vector2f squareScale);
	void setOrientation(int orientation);
	void setIt(float it);
	float getIt() const;
	int getId() const;
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	int getOrientation() const;
	void addCommand(std::string infos);
	int getQueueSize() const;
	std::string getCommand(int id) const;
	int getQueueIt() const;
	void setQueueIt(int i);
	void crossMap(int o, sf::Vector2f distance, sf::Vector2i mapSize);
	void crossMap2(int o, sf::Vector2f distance, sf::Vector2i mapSize);
	void setPicInfos(int x, int y, int state);
	sf::Vector3i getPicInfos() const;
	void setLevel(int level);
	sf::Sprite getPicSprite() const;
	bool initPic();
	void picPos();
	void moveAura();
	int findIncPlayer(sf::Vector2i picPos);
private:
	int id;
	sf::Vector2f position;
	int orientation;
	int level;
	std::string team;
	sf::Texture texture;
	sf::Texture texture2;
	sf::Vector2u textureSize;
	sf::Vector2f scale;
	sf::Sprite sprite;
	bool alive;
	int movePattern;
	bool moving;
	float it;
	std::vector<std::string> commandQueue;
	int queueIt;
	sf::Vector3i picInfos;
	sf::Texture picTexture;
	sf::Sprite picSprite;
	sf::Vector2u picTSize;
};