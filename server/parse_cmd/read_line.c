/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** Getline from fd function
*/

#include "server.h"

const int FIRST = 1;
const int SND = 2;

static char *concate_str(char *first, char *snd, int state)
{
	int len = strlen(first);
	int len2 = strlen(snd);
	char *ret = malloc(sizeof(char) * (len + len2 + 1));
	int i = 0;

	if (!ret)
		return (NULL);
	for (int j = 0; first[j]; j++)
		ret[i++] = first[j];
	for (int j = 0; snd[j]; j++)
		ret[i++] = snd[j];
	ret[i] = 0;
	if (state == FIRST || state == FIRST + SND)
		free(first);
	if (state == SND || state == FIRST + SND)
		free(snd);
	return (ret);
}

static char *free_lines(char *str, char *tmp)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	return (NULL);
}

static bool check_msg_validity(char *str)
{
	int i = 0;

	if (!str || strlen(str) < 2)
		return (false);
	for (; str[i]; i++)
		if (i != 0 && str[i] == '\n')
			return (true);
	return (false);
}

static char *swap_strings(char *tmp)
{
	char *str;

	tmp[strlen(tmp) - 1] = 0;
	str = strdup(tmp);
	tmp[strlen(tmp) + 1] = 0;
	free(tmp);
	return (str);
}

char	*get_line(FILE *stream)
{
	char *str = NULL;
	char *tmp = NULL;
	size_t size = 0;

	if (!stream)
		return (NULL);
	if (getline(&tmp, &size, stream) == -1)
		return (free_lines(NULL, tmp));
	for (; !check_msg_validity(tmp);) {
		if (getline(&str, &size, stream) == -1)
			return (free_lines(str, tmp));
		tmp = concate_str(tmp, str, FIRST + SND);
		str = NULL;
	}
	str = swap_strings(tmp);
	return (str);
}