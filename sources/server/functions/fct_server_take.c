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
	                    {THYSTAME, "thystame"},
                {THYSTAME, "thystame"},

};

static char *take_it(int stone, t_env *e, int fd)
{
	 for (int i = 0; i < 6; i++) {
		 if (stone == stonetab[i].stone) {
			 printf("%s\n", stonetab[i].print);
			 e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][stone] = STONE;
			 return (stonetab[i].print);

		 }
	 }
	 return (NULL);
}

int fct_server_take(char *cmd_line, int fd, t_env *e)
{	
	(void)cmd_line;
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
			if (strncmp("linemate", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 8) == 0)
				e->inventory[fd].stone.linemate =  e->inventory[fd].stone.linemate + 1;
			if (strncmp("deraumere", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 9) == 0)
				e->inventory[fd].stone.deraumere =  e->inventory[fd].stone.deraumere + 1;
			if (strncmp("sibur", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 5) == 0 )
				e->inventory[fd].stone.sibur =  e->inventory[fd].stone.sibur + 1;
			if (strncmp("mendiane", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 8) == 0)
				e->inventory[fd].stone.mendiane =  e->inventory[fd].stone.mendiane + 1;
			if (strncmp("phiras", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 6) == 0)
				e->inventory[fd].stone.phiras =  e->inventory[fd].stone.phiras + 1;
			if (strncmp("thystane", take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd), 8) == 0)
				e->inventory[fd].stone.thystame =  e->inventory[fd].stone.thystame + 1;

			dprintf(fd, "%s\n", "ok");
		}
	}
	else
		dprintf(fd, "%s\n", "ko");
	return (0);
}
