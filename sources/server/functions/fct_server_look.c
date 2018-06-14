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

static void print_stone(int stone, int fd)
{
	for (int i = 0; i < 6; i++) {
		if (stone == stonetab[i].stone)
			dprintf(fd, " %s", stonetab[i].print);
	}

}

static void print_case(int fd, t_env *e, vec_t pos)
{
	if (pos.x < 0)
		pos.x = pos.x + e->infos->map_size.x - 1;
	else if (pos.y < 0)
		pos.y = pos.y + e->infos->map_size.y - 1;
	else if (pos.y >= e->infos->map_size.y)
		pos.y = pos.y - (e->infos->map_size.y - 1);
	else if (pos.x >= e->infos->map_size.x)
		pos.x = pos.x - (e->infos->map_size.x - 1);
	if (e->infos->map[pos.x][pos.y][0] == STONE) {
		dprintf(fd, "bite,");
	else
		dprintf(2, "bite,");
}

static void print_lines(int fd, t_env *e, int nbr_of_lines)
{
	//left
	int i = nbr_of_lines * -1;
	vec_t case_pos = e->pos_ia[fd];
	vec_t atm_pos = case_pos;

	for (int x = 1; x < nbr_of_lines; x++) {
		case_pos.y -= 1;
		atm_pos = case_pos;
		for (i = x * -1; i <= x; i++) {
			atm_pos.x = case_pos.x + i;
			print_case(fd, e, atm_pos);
		}
	}
	dprintf(fd, "\n");
}

int fct_server_look(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	e->vision_field[fd] = 3;
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		dprintf(fd, "[player");
		for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
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
