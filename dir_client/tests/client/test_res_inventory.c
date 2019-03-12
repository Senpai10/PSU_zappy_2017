/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test res inventory
*/

#include <criterion/criterion.h>
#include "client.h"

Test(assert, res_inventory3)
{
        client_t self;
	char *str[] = {"food 4", NULL};
	char *str2[] = {"food 17", NULL};

	self.state = 0;
	update_needs_life(&self, str);
        cr_assert(abs(self.state) == 64);
	self.state = 64;
	update_needs_life(&self, str2);
        cr_assert(abs(self.state) == 0);
}

Test(assert, res_inventory2)
{
        client_t self;
	char *str[] = {"linemate 1", "deraumere 2", "sibur 1", "mendiane 3",
			NULL};
	char *str2[] = {"linemate 1", "sibur 3", "deraumere 2",
			"phiras 1", NULL};
	char *str3[] = {"linemate 2", "sibur 2", "phiras 2",
			"deraumere 2", "mendiane 2", "thystame 1", NULL};

	self.state = 15;
        need_for_lvl_five(&self, str);
        cr_assert(abs(self.state) == 128);
	self.state = 23;
	need_for_lvl_six(&self, str2);
        cr_assert(abs(self.state) == 128);
	self.state = 63;
	need_for_lvl_seven(&self, str3);
        cr_assert(abs(self.state) == 128);
}

Test(assert, res_inventory)
{
        client_t self;
	char *str[] = {"linemate 1", "sibur 1", "food 4", NULL};
	char *str2[] = {"linemate 1", "sibur 1", "deraumere 1", NULL};
	char *str3[] = {"linemate 2", "sibur 1", "phiras 2", NULL};
	char *str4[] = {"linemate 1", "sibur 2", "deraumere 1",
			"phiras 1", NULL};

	self.state = 1;
        need_for_lvl_one(&self, str);
        cr_assert(abs(self.state) == 128);
	self.state = 7;
	need_for_lvl_two(&self, str2);
        cr_assert(abs(self.state) == 128);
	self.state = 21;
	need_for_lvl_three(&self, str3);
        cr_assert(abs(self.state) == 128);
	self.state = 23;
	need_for_lvl_four(&self, str4);
        cr_assert(abs(self.state) == 128);
}