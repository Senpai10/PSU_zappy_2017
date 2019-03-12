/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** str to wordtab custom for look
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* @brief Count the number of word present in the string seperated by a
* delimeter
* @param str (char *) It's the look's return (Vision of the IA)
* @param c (char) The delimeter
* @return int return the number of word
*/
int count_words(char *str, char c)
{
	int word = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			word++;
		if (str[i] != '\0')
			i++;
	}
	return (word + 1);
}

/**
* @brief Retrieves the word's len to malloc
*
* @param str (char *) It's the look's return (Vision of the IA)
* @param c (char) The delimeter
* @param i (int) The index (where we are in the string)
* @return int return the word's len
*/
int len_word(char *str, char c, int i)
{
	int len = 0;

	while (str[i] != c && str[i] != '\0') {
		i++;
		len++;
	}
	return (len);
}

/**
* @brief Copy character by character before the delimeter
*
* @param str (char *) It's the look's return (Vision of the IA)
* @param c (char) The delimeter
* @param i (int) The index (where we are in the string)
* @return char* return an new string copied without the delimeter
*/
char *str_dup(char *str, char c, int *i)
{
	int j = *i;
	int b = 0;
	char *new = malloc(sizeof(char) * (len_word(str, c, j) + 1));

	if (new == NULL)
		return (NULL);
	while (str[*i] != c && str[*i] != '\0') {
		new[b] = str[*i];
		b++;
		*i += 1;
	}
	new[b] = '\0';
	return (new);
}

/**
* @brief A Str_to_WordTab custom to handle the Look's return
* (EX : [player,,,linemate])
* @param str (char *) It's the look's return (Vision of the IA)
* @param c (char) The delimeter (generally it's a coma)
* @return char** return the vision parsed
*/
char	**stw_look(char *str, char c)
{
	char **tab = malloc(sizeof(char *) * (count_words(str, c) + 1));
	int i = 0;
	int a = 0;

	if (tab == NULL)
		return (NULL);
	while (str[i] != '\0') {
		if (str[i] != c && str[i] != ']')
			tab[a] = str_dup(str, c, &i);
		a++;
		if ((str[i] == c && (str[i + 1] == c || str[i + 1] == ']'))
		&& str[i] != '\0') {
			tab[a] = strdup(" ");
			i++;
		} else if (str[i] != '\0')
			i++;
	}
	tab[a] = NULL;
	return (tab);
}
