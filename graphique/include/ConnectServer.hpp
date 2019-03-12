/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#pragma once

class ConnectServer
{
public:
	ConnectServer(sf::RenderWindow&);
	~ConnectServer();
	int startConnect();
	int displayBackground();
	int manageEvent();
	int handleMouseAction(sf::Event);
	int addToString(sf::Event);
	void tryConnect();
	sf::TcpSocket& getSocket();
	void delToString();
	void setClick(int state);
	void setString(std::string str, int nb);
	std::string getString(int nb) const;
private:
	sf::TcpSocket socket;
	sf::Socket::Status status;
	sf::Texture backgroundTexture;
	sf::Texture frameTexture;
	sf::Sprite backgroundSprite;
	sf::Sprite frameSprite;
	sf::Text portText;
	sf::Text hostText;
	std::string hostString;
	std::string portString;
	sf::RenderWindow& window;
	sf::Color vaporBlue;
	sf::Font font;
	sf::Music connectMusic;
	int clickState;
	int connected;
};