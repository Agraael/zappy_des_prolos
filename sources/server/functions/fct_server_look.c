/*
** EPITECH PROJECT, 2018
** slt
** File description:
** ite
*/

#include "struct.h"

static const t_printtab stonetab[] = {
        {LINEMATE, "linemate"},
        {DERAUMERE, "deraumere"},
        {SIBUR, "sibur"},
        {MENDIANE, "mendiane"},
        {PHIRAS, "phiras"},
        {THYSTAME, "thystame"}
};

static void print_stone(int stone)
{
	for (int i = 0; i < 6; i++) {
		if (stone == stonetab[i].stone)
			printf(" %s", stonetab[i].print);
	}

}

int fct_server_look(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		printf("[player");
		for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
			print_stone(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]);
		}
		if (e->vision_field[fd] == 1) {
			printf("]\n");
			return (0);
		}
		printf(",");
		printf("merde %d\n", e->vision_field[fd]);
	}
	else {
		printf("[player");
		if (e->vision_field[fd] == 1) {
                        printf("]\n");
                        return (0);
                }
		printf(",");
	}
	/*if (e->dir[fd] == UP) {
		printf("up\n");
	}
	printf("\n");*/
	return (0);
}
