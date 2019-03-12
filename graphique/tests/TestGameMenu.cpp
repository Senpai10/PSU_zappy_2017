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

Test(loadTexture, loadFail)
{
	GameMenu menu;
	//cr_assert(menu.loadAndDrawIntro("lol") == -1);
	cr_assert(menu.loadAndDrawIntro("./ressources/login/bg.png") == 0);
}