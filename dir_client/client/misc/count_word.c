/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** count word
*/

#include "client.h"

/**
* @brief Allows to skip the character (duplicate)
*
* @param str (char *) All of the object on one tile
* @param c (char) The delimeter which separe the word (genreally a space)
* @param i (int) The index where we are
* @return int return the new index
*/
int skip_char(char *str, char c, int i)
{
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}

/**
* @brief Allows to distinguish if there are several object on one tile
*
* @param str (char *) All of the object on one tile
* @param c (char) The delimeter which separe the word (genreally a space)
* @return int retun the number of word
*/
int count_word(char *str, char c)
{
	int word = 0;
	int i = 0;

	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != '\0') {
		if (str[i] == c) {
			word++;
			i = skip_char(str, c, i);
		}
		if (str[i] != '\0')
			i++;
	}
	return (word + 1);
}
