/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test create id
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, create_od)
{
        int value = create_random_id();

        cr_assert(value >= 0);
}