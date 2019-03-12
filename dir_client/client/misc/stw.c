/*
** EPITECH PROJECT, 2018
** STR_TO_WORDTAB
** File description:
** functions for stw delim functions
*/

#include "stw.h"
#include "releaser.h"

/**
* @brief work like strlen but with an additional delimiter as stopper
* i (int) iterator
* @param s (char *) string to iterate through
* @param delim (char) delimiter
* @return int containing the number of characters read
*/
int stw_diff(char *s, char delim)
{
	int i = 0;

	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

/**
* @brief iterate while the string is on the delimiter
* i (int) iterator
* @param s (char *) string to iterate through
* @param delim (char) delimiter
* @return int index of the next character different from delimiter
*/
int stw_occ(char *s, char delim)
{
	int i = 0;

	while (s[i] && s[i] == delim)
		i++;
	return (i);
}

/**
* @brief iterate through a string and count the number of delimiter found
* i (int) iterator
* count (int) times of delimiter encountered
* @param s (char *) string to iterate through
* @param delim (char) delimiter
* @return int total count of delimiter in the string
*/
int stw_sep(char *s, char delim)
{
	int i = 0;
	int count = 1;

	while (s[i]) {
		if (s[i] == delim) {
			i += stw_occ(&s[i], delim);
			count++;
		} else
			i++;
	}
	return (count);
}

/**
* @brief similar to strdup but stop to a certain delimiter
* new (char *) new string to return
* n (int) iterator
* @param s (char *) string to duplicate
* @param delim (char) delimiter
* @return char* containing the newly created string
*/
char *stw_dup(char *s, char delim)
{
	char *new = malloc(sizeof(char) * (stw_diff(s, delim) + 1));
	int n = 0;

	if (!new)
		return (NULL);
	for (int i = 0; s[i] && s[i] != delim; i++) {
		new[n] = s[i];
		n++;
	}
	new[n] = '\0';
	return (new);
}

/**
* @brief take a string as parameter and split it in an array
* depending on the delimiter given
* tab (char **) used to contain the words splitted
* i (int) string iterator
* y (int) array index iterator
* @param s (char *) string to split
* @param delim (char) delimiter for splitting
* @return char** contain the array of words
*/
char **stw(char *s, char delim)
{
	char **tab = malloc(sizeof(char *) * (stw_sep(s, delim) + 1));
	int i = 0;
	int y = 0;

	if (!tab)
		return (NULL);
	while (s[i] == delim && s[i] != '\0')
		i++;
	while (s[i]) {
		if (s[i] != delim) {
			tab[y] = stw_dup(&s[i], delim);
			i += stw_diff(&s[i], delim);
			y++;
		} else
			i++;
		if (!tab[y - 1]) {
			free_tab(tab);
			return (NULL);
		}
	}
	tab[y] = NULL;
	return (tab);
}
