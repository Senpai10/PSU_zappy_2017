/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#pragma once

#include <SFML/Audio.hpp>
#include "MenuControllers.hpp"

class GameMenu {
public:
	GameMenu();
	~GameMenu();
	int displayIntro();
	int displayLoop();
	int loadAndDrawIntro(const std::string);
	int handleLoop(const std::string);
	int handleMenuAction();
	void handleClosure();
	MenuControllers getControll() const;
	sf::RenderWindow& getWindow();
private:
	sf::RenderWindow window;
	sf::Texture wipTexture;
	sf::Sprite wipSprite;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Music menuMusic;
	std::string fileNameIntro;
	std::string fileNameLoop;
	MenuControllers controll;
};