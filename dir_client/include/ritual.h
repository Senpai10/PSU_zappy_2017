/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** file for ritual functions
*/

#pragma once

static list_res_t *ritual_for_level_three(client_t *, list_res_t *);
static list_res_t *ritual_for_level_two(client_t *, list_res_t *);
static list_res_t *ritual_for_level_one(client_t *, list_res_t *);

typedef	list_res_t *(*ritual_t)(client_t *, list_res_t *);

extern const ritual_t ritual_tab[];