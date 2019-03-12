/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** a curstom strcmp
*/

#include "client.h"

/**
* @brief A custom Strcmp which compare character by character but skip '[', ']'
* and ' '
* @param origin (char *) the first string
* @param compared (char *) the second string
* @return int return 0 if the strings are identical else -1
*/
int my_strcmp(char *origin, char *compared)
{
	int i = 0;
	int j = 0;

	while (origin[i] != '\0' && compared[j] != '\0') {
		if (compared[j] == '[' || compared[j] == ']'
		|| compared[j] == ' ')
			j++;
		if (origin[i] != compared[j])
			return (-1);
		i++;
		j++;
	}
	return (0);
}

/**
* @brief Compares at most the first n bytes of str1 and str2 like a true
* strncmp but skip the character : '[', ']' and ' '
* @param origin (char *) The first string
* @param compared (char *) The second String
* @param n (int) represent the first n bit
* @return int return 0 if the strings are identical else -1
*/
int my_strncmp(char *origin, char *compared, int n)
{
	int i = 0;
	int j = 0;

	while (n != 0) {
		if (compared[j] == '[' || compared[j] == ']'
		|| compared[j] == ' ')
			j++;
		if (origin[i] != compared[j])
			return (-1);
		i++;
		j++;
		n--;
	}
	return (0);
}