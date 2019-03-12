/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test count word
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, count_word)
{
        int value = count_word("   linemate food sibur   phiras", ' ');

        cr_assert(value == 4);
}