/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test check_error
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, check_error)
{
        char *str[] = {"zappy_ai", "-p", "1111", "-n", "test", "-h",
			"localhost"};
        char *str2[] = {"zappy_ai", "-p", "1111", "-n", "test"};
        char *str3[] = {"zappy_ai", "-p", "azeaze", "-n", "test"};
        char *str4[] = {"zappy_ai", "azea", "1111", "-n", "test"};
        char *str5[] = {"zappy_ai", "-p"};
        int value = check_error(7, str);

        cr_assert(value == 0);
        value = check_error(5, str2);
        cr_assert(value == 0);
	value = check_error(5, str3);
        cr_assert(value == 84);
	value = check_error(5, str4);
        cr_assert(value == 84);
	value = check_error(2, str5);
        cr_assert(value == 84);
}
