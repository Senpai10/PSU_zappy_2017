/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** array of functions pointers for parser
*/

#pragma once

typedef void (*message_parsers)(message_t **, char *);

static void parse_message_optional(message_t **, char *);
static void parse_message_player(message_t **, char *);
static void parse_message_tile(message_t **, char *);
