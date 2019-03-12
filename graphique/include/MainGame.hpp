/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#pragma once

#include "Trantorian.hpp"
#include "Tile.hpp"

class MainGame
{
public:
	MainGame(sf::RenderWindow&, sf::TcpSocket&);
	~MainGame();
	std::string getCommand();
	int startGame();
	int handleMap(const std::string command);
	int handleCommands();
	int handleWaitingCommands();
	void handleEvents();
	void initTabs();
	void displayBackground();
	void displayInfos();
	std::vector<std::string> getCommandInfos(const std::string infos);
	int newTrantorian(const std::string infos);
	void	displayTrantorians();
	int initMovement(const std::string infos);
	void tryMove();
	void moveTrantorian(int id);
	void moveLeft(int id);
	void moveUp(int id);
	void moveRight(int id);
	void moveDown(int id);
	int organizeCommand(int id, const std::string infos);
	int startWaitingCommand(const std::string command);
	void handleZoom(const sf::Event event);
	int manageTile(const std::string infos);
	int tileExist(int x, int y);
	void updateTile(const std::vector<std::string> iaInfos);
	void initRessources();
	int expulseTrantorian(const std::string infos);
	void displayTilesContent();
	void drawTile(Tile *);
	void setAndDraw(Tile *tile, int nb, float posx, float posy);
	int checkEdge(float x, float y, int i);
	int checkEdge2(float x, float y, int i);
	void initFood();
	int startIncantation(std::string infos);
	void tryPic();
	int endIncantation(const std::string infos);
private:
	sf::RenderWindow& window;
	sf::TcpSocket& socket;
	sf::Texture squareTexture;
	sf::Texture ressourcesTexture;
	sf::Texture foodTexture;
	sf::Sprite square;
	sf::Sprite ressourcesSprite[7];
	typedef int (MainGame::*doCommand)(std::string);
	std::map<int, doCommand> functionTab;
	std::string *tabCommand[10];
	sf::Vector2i mapSize;
	std::vector<Trantorian*> tList;
	std::vector<Tile*> tiles;
	sf::Vector2f distance;
	sf::Vector2f scale;
	sf::Vector2u textureSize;
	sf::View view;
	sf::Vector2f pos;
	sf::Music gameMusic;
};