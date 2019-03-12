/*
** EPITECH PROJECT, 2018
** Project
** File description:
** project file
*/

#include <criterion/criterion.h>
#include "../include/ZappyGraphic.hpp"
#include "Tile.hpp"

Test(initTile, testGoodInit)
{
	Tile newTile;
	std::vector<std::string> iaInfos;

	iaInfos.push_back("1");
	iaInfos.push_back("2");
	iaInfos.push_back("3");
	iaInfos.push_back("4");
	iaInfos.push_back("5");
	iaInfos.push_back("6");
	iaInfos.push_back("7");
	iaInfos.push_back("8");
	iaInfos.push_back("9");
	iaInfos.push_back("10");
	newTile.initTile(iaInfos);
	cr_assert(newTile.getPosx() == 2 && newTile.getPosy() == 3
		&& newTile.getFood() == 4 && newTile.getStone(0) == 5
		&& newTile.getStone(1) == 6 && newTile.getStone(2) == 7
		&& newTile.getStone(3) == 8 && newTile.getStone(4) == 9
		&& newTile.getStone(5) == 10);
}