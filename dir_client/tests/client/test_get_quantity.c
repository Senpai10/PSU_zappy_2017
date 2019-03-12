/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test get quantity
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, get_quantity)
{
        int value = get_quantity("linemate 4");

        cr_assert(value == 4);
        value = get_quantity("sibur");
        cr_assert(value == -1);
}