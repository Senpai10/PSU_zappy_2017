/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#pragma once

class MenuControllers {
public:
	MenuControllers();
	~MenuControllers();
	void drawTitles();
	void initColors();
	void handleState(const sf::Event);
	void handleNavigationMenu();
	void handleReturnState();
	sf::Text getPlay() const;
	sf::Text getOptions() const;
	sf::Text getExit() const;
	int getState() const;
private:
	int state;
	sf::Text play;
	sf::Text options;
	sf::Text exit;
	sf::Font menuFont;
	sf::Color blue;
	sf::Color light;
};