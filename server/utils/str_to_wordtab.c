/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** str_to_wordtab
*/

#include "server.h"

static int	check_carac_a(const char *str, int i, int a)
{
	if ((str[i] > 0 && str[i] < 48) || (str[i] == 32)
		|| (str[i] > 57 && str[i] < 65)
		|| (str[i] > 90 && str[i] < 97)
		|| (str[i] > 122) || str[i] == '\0')
		return (a);
	return (a + 1);
}

static int	check_carac(const char *str, int i)
{
	if ((str[i] > 0 && str[i] < 47) || (str[i] == 32)
		|| (str[i] > 57 && str[i] < 65)
		|| (str[i] > 90 && str[i] < 97)
		|| (str[i] > 122) || str[i] == '\0')
		return (0);
	return (1);
}

/**
* \brief Count the word in a str.
*
* \param str The str to convert
* \return char** Return the tab malloc from str.
*/
char	**count_words(const char *str)
{
	int	i = 0;
	int	words = 1;
	char	**tab;

	while (str[i] != '\0') {
		if ((str[i] > 0 && str[i] < 47)
		|| (str[i] == 32)
		|| (str[i] > 57 && str[i] < 65)
		|| (str[i] > 90 && str[i] < 97)
		|| (str[i] > 122))
			words++;
		i++;
	}
	tab = malloc((sizeof(char *) * words) + 1);
	if (tab == NULL)
		return (NULL);
	return (tab);
}

/**
* \brief Create a double array from a array.
*
* \param str The array to convert
* \return char** Return the double array.
*/
char	**str_to_wordtab(char *str)
{
	char	**tab = count_words(str);
	int	x = 0;
	int	y = 0;
	int	c;
	while ((int)strlen(str) > y) {
		tab[x] = malloc(sizeof(char) * strlen(str) + 1);
		if (tab[x] == NULL)
			return (NULL);
		c = 0;
		while (check_carac(str, y) != 0) {
			tab[x][c] = str[y];
			c++;
			y++;
		}
		tab[x][c] = '\0';
		x = check_carac_a(str, y - 1, x);
		y++;
	}
	tab[x] = NULL;
	return (tab);
}