/*
** EPITECH PROJECT, 2018
** str
** File description:
** to_wordtab
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

static int maloc_str(char *str, int x, char delim)
{
	int compteur2 = 0;

	while (str[x] && str[x] != delim) {
		compteur2 = compteur2 + 1;
		x = x + 1;
	}
	return (compteur2);
}

static int words_number(char *str, char delim)
{
	int x = 0;
	int compteur = 1;

	while (str[x]) {
		if (str[x] == delim)
			compteur = compteur + 1;
		x = x + 1;
	}
	return (compteur);
}

char **my_str_to_wordtab(char *str, char delim)
{
	char **tab = malloc(sizeof(char *) * (words_number(str, delim) + 1));
	int x = 0;
	int y = 0;
	int z = 0;

	if (tab == NULL)
		return (NULL);
	while (str && str[x] != '\0') {
		y = 0;
		if ((tab[z] = malloc(sizeof(char) *
				(maloc_str(str, x, delim) + 1))) == NULL)
			return (NULL);
		while (str[x] && str[x] != delim)
			tab[z][y++] = str[x++];
		tab[z][y] = '\0';
		z = z + 1;
		x += (str[x] != '\0');
	}
	tab[z] = '\0';
	return (tab);
}
