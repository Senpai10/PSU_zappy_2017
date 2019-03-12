/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#include <criterion/criterion.h>
#include "../include/ZappyGraphic.hpp"
#include "../include/GameMenu.hpp"
#include "../include/MenuControllers.hpp"
#include "../include/ConnectServer.hpp"

Test(connectServer, addToString)
{
	sf::Event event;
	GameMenu menu;
	ConnectServer server(menu.getWindow());

	server.setClick(1);
	server.setString("a", 0);
	cr_assert(server.addToString(event) == 0);
	server.setString("aaaaaaaaaaa", 0);
	cr_assert(server.addToString(event) == 0);
	server.setClick(2);
	server.setString("b", 0);
	cr_assert(server.addToString(event) == 0);
	server.setString("bbbbbbbbbbb", 0);
	cr_assert(server.addToString(event) == 0);
}

Test(connectServer, delToString)
{
	GameMenu menu;
	ConnectServer server(menu.getWindow());

	server.setClick(1);
	server.setString("a", 0);
	server.delToString();
	server.setString("aaaaaaaaaaa", 0);
	server.delToString();
	cr_assert(strcmp(server.getString(0).c_str(), "aaaaaaaaaa") != 0);
	server.setClick(2);
	server.setString("b", 0);
	server.delToString();
	server.setString("bbbbbbbbbbb", 0);
	server.delToString();
	cr_assert(strcmp(server.getString(0).c_str(), "bbbbbbbbbb") == 0);
}