/*
** EPITECH PROJECT, 2018
** generator
** File description:
** of map
*/

#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

static const t_stonetab stonetab[] = {
	{0, LINEMATE},
	{1, DERAUMERE},
	{2, SIBUR},
	{3, MENDIANE},
	{4, PHIRAS},
	{5, THYSTAME}
};

static char **randomly_fill_with_minerals(char **line, int size_y)
{
	int mineral = 0;
	int y = 0;

	for (y = 0; y < size_y; y++) {
		if ((line[y][0] == FOOD) || (rand() % 6 == 0))
			continue ;
                mineral = rand() % 6;
		for (int i = 0; i < 6; i++)
			if (mineral == stonetab[i].id)
				line[y][0] = stonetab[i].stone;
        }
        line[y]	= '\0';
	return (line);
}

static char **randomly_fill_with_food(int size_y)
{
	char **line = malloc(sizeof(char *) * (size_y + 1));
	int y = 0;

	for (y = 0; y < size_y; y++) {
		line[y] = malloc(sizeof(char) * 2);
		if (rand() % 7 == 3)
			line[y][0] = FOOD;
		else
			line[y][0] = STONE;
		line[y][1] = '\0';
	}
	line[y] = '\0';
	return (line);
}

void generate_map(infos_t *infos_game)
{
	int x = 0;

	srand(time(NULL));
	infos_game->map = malloc(sizeof(char **) * (infos_game->map_size.x + 1));
	for (x = 0; x < infos_game->map_size.x; x++) {
		infos_game->map[x] =
			randomly_fill_with_food(infos_game->map_size.y);
	}
	infos_game->map[x] = '\0';
	for (x = 0; x < infos_game->map_size.x; x++) {
		infos_game->map[x] =
			randomly_fill_with_minerals(infos_game->map[x],
							infos_game->map_size.y);
	}
}
