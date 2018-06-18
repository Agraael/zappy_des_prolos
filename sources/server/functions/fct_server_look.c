/*
** EPITECH PROJECT, 2018
** slt
** File description:
** ite
*/

#include "fcts.h"
#include "struct.h"

static const t_printtab stonetab[] = {
        {LINEMATE, "linemate"},
        {DERAUMERE, "deraumere"},
        {SIBUR, "sibur"},
        {MENDIANE, "mendiane"},
        {PHIRAS, "phiras"},
        {THYSTAME, "thystame"}
};

static void print_stone(int stone, int fd)
{
	for (int i = 0; i < 6; i++) {
		if (stone == stonetab[i].stone)
			dprintf(fd, "%s", stonetab[i].print);
	}

}

void print_case(int fd, t_env *e, vec_t pos)
{
	if (pos.x < 0)
		while (pos.x < 0)
			pos.x = pos.x + (e->infos->map_size.x);
	if (pos.y < 0)
		while (pos.y < 0)
			pos.y = pos.y + (e->infos->map_size.y);
	if (pos.y >= e->infos->map_size.y)
		while (pos.y >= e->infos->map_size.y)
			pos.y = pos.y - (e->infos->map_size.y);
	if (pos.x >= e->infos->map_size.x)
		while (pos.x >= e->infos->map_size.x)
			pos.x = pos.x - (e->infos->map_size.x);
	dprintf(2, "pos: %d %d\n", pos.x, pos.y);
	if (e->infos->map[pos.x][pos.y][0] == STONE)
		dprintf(fd, ",");
	else {
		for (int x = 0; e->infos->map[pos.x][pos.y][x]; x++) {
			print_stone(e->infos->map[pos.x][pos.y][x], fd);
			if (e->infos->map[pos.x][pos.y][x + 1])
				dprintf(fd, " ");
		}
		dprintf(fd, ",");
	}
}

static void print_lines(int fd, t_env *e, int nbr_of_lines)
{
	if (e->dir[fd] == UP)
		print_lines_up(fd, e, nbr_of_lines);
	else if (e->dir[fd] == DOWN)
		print_lines_down(fd, e, nbr_of_lines);
	if (e->dir[fd] == LEFT)
		print_lines_left(fd, e, nbr_of_lines);
	if (e->dir[fd] == RIGHT)
		print_lines_right(fd, e, nbr_of_lines);
	dprintf(fd, "]\n");
}

static void print_map(t_env *e)
{
	for (int i = 0; i < e->infos->map_size.x; i++) {
		for (int j = 0; j < e->infos->map_size.y; j++) {
			printf("[");
			for (int x = 0; e->infos->map[i][j][x] != '\0'; x++)
				printf("%d-", e->infos->map[i][j][x]);
			printf("]");
		}
		printf("\n");
	}
}

int fct_server_look(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	e->vision_field[fd] = 3;
	printf("%d, %d - %d - %d", e->infos->map_size.x, e->infos->map_size.y, e->pos_ia[fd].x, e->pos_ia[fd].y);
	print_map(e);
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		dprintf(fd, "[player");
		for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
			dprintf(fd, " ");
			print_stone(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], fd);
		}
		if (e->vision_field[fd] == 1) {
			dprintf(fd, "]\n");
			return (0);
		}
		dprintf(fd, ",");
	}
	else {
		dprintf(fd, "[player");
		if (e->vision_field[fd] == 1) {
                        dprintf(fd, "]\n");
                        return (0);
                }
		dprintf(fd, ",");
	}
	print_lines(fd, e, e->vision_field[fd]);
	return (0);
}
