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
	{FOOD, "food"},
        {THYSTAME, "thystame"}
};

static void print_stone(int stone, int fd)
{
	for (int i = 0; i < 7; i++) {
		if (stone == stonetab[i].stone)
			dprintf(fd, "%s", stonetab[i].print);
	}

}

static void print_players(t_env *e, vec_t pos, int fd)
{
	for (int x = 0; x < MAX_FD; x++) {
                if (e->fd_type[x] == FD_CLIENT && x != fd &&
                    e->pos_ia[x].x == pos.x &&
                    e->pos_ia[x].y == pos.y) {
			dprintf(fd, " player");
                }
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
	if (e->infos->map[pos.x][pos.y][0] == STONE)
		dprintf(fd, ",");
	else {
		for (int x = 0; e->infos->map[pos.x][pos.y][x]; x++) {
			print_stone(e->infos->map[pos.x][pos.y][x], fd);
			if (e->infos->map[pos.x][pos.y][x + 1])
				dprintf(fd, " ");
		}
		print_players(e, pos, fd);
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

int fct_server_look(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		dprintf(fd, "[player");
		print_players(e, e->pos_ia[fd], fd);
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
