/*
** EPITECH PROJECT, 2018
** utils
** File description:
** fcts
*/

#include "struct.h"
#include <string.h>
#include <stdlib.h>

vec_t create_random_pos(vec_t map_size)
{
	vec_t pos_ia;

	pos_ia.x = rand() % (map_size.x - 1);
	pos_ia.y = rand() % (map_size.y - 1);
	return (pos_ia);
}

char *epur(char *test)
{
	char *new = NULL;
	int x = 0;
	int y = 0;
	int i = 0;

	for (; test[i] && test[i] != '\r' && test[i] != '\n'; i++);
	test[i] = '\0';
	new = malloc(sizeof(char) * strlen(test) + 1);
	while (test[x]) {
		new[y] = test[x];
		x++;
		(test[x] &&
			(test[x] == ' ' || test[x] == '\t') && (x - 1 >= 0) &&
			(test[x - 1] == ' ' || test[x - 1] == '\t')) ?
			y = y : y++;
	}
	new[y] = '\0';
	return (new);
}
