/*
** EPITECH PROJECT, 2018
** slt
** File description:
** bfrz
*/

#include "struct.h"
#include "fcts.h"
#include <string.h>

static const t_printtab stonetab[] = {
        {LINEMATE, "linemate"},
	{DERAUMERE, "deraumere"},
        {SIBUR, "sibur"},
	{MENDIANE, "mendiane"},
        {PHIRAS, "phiras"},
        {THYSTAME, "thystame"}
};

static char *take_it(int stone, t_env *e, int fd)
{
	 for (int i = 0; i < 6; i++) {
		 if (stone == stonetab[i].stone) {
			 printf("%s\n", stonetab[i].print);
			 e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] = STONE;
			 return (stonetab[i].print);
		 }
	 }
	 return (NULL);
}

int fct_server_take(char *cmd_line, int fd, t_env *e)
{	
	(void)cmd_line;
	printf("oui\n");
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
			if (strncmp("linemate", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 8) == 0)
				e->inventory[fd].linemaute =  e->inventory[fd].linemaute + 1;
			else if (strncmp("deraumere", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 9) == 0)
				e->inventory[fd].deraumere =  e->inventory[fd].deraumere + 1;
			else if (strncmp("sibur", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 5) == 0 )
				e->inventory[fd].sibur =  e->inventory[fd].sibur + 1;
			else if (strncmp("mendiane", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 8) == 0)
				e->inventory[fd].mendiane =  e->inventory[fd].mendiane + 1;
			else if (strncmp("phiras", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 6) == 0)
				e->inventory[fd].phiras =  e->inventory[fd].phiras + 1;
			else if (strncmp("thystane", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 8) == 0)
				e->inventory[fd].thystame =  e->inventory[fd].thystame + 1;
			dprintf(fd, "%s\n", "ok");
		}
	}
	else
		dprintf(fd, "%s\n", "ko");
	return (0);
}
