/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test strcmp custom
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, strcmp_custom)
{
        int value = my_strcmp("player", "[player");

        cr_assert(value == 0);
        value = my_strcmp("linemate", "linemate]");
        cr_assert(value == 0);
	value = my_strcmp("sibur", " sibur");
        cr_assert(value == 0);
	value = my_strcmp("player", "azeplayer");
        cr_assert(value == -1);
        value = my_strncmp("linemate", "linemate]", 8);
        cr_assert(value == 0);
	value = my_strncmp("sibur", " sibur", 5);
        cr_assert(value == 0);
	value = my_strncmp("player", "azeplayer", 6);
        cr_assert(value == -1);
}