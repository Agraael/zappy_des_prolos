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
        {FOOD, "food"},
};

static int take_it(int stone, t_env *e, int fd, int x)
{
	 for (int i = 0; i < 7; i++) {
		 if (stone == stonetab[i].stone) {
			 e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x] = STONE;
			 return (stonetab[i].stone);
		 }
	 }
	 return (0);
}

static void eat_it(t_env *e, int fd)
{
    if  (e->inventory[fd].food == 1260)
        return;
    else if (e->inventory[fd].food >= 1134)
        e->inventory[fd].food = 1260;
    else
        e->inventory[fd].food += 126;
}

int fct_server_take(char *cmd_line, int fd, t_env *e)
{	
	(void)cmd_line;
	int stone = 0;
	if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] != STONE) {
		for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
		    stone = take_it(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x], e, fd, x);
		    if (stone == 1)
                e->inventory[fd].stone.deraumere =  e->inventory[fd].stone.deraumere + 1;
            if (stone == 2)
                e->inventory[fd].stone.sibur =  e->inventory[fd].stone.sibur + 1;
            if (stone == 3)
                e->inventory[fd].stone.mendiane =  e->inventory[fd].stone.mendiane + 1;
            if (stone == 4)
                e->inventory[fd].stone.phiras =  e->inventory[fd].stone.phiras + 1;
            if (stone == 5)
                e->inventory[fd].stone.thystame =  e->inventory[fd].stone.thystame + 1;
            if (stone == 6)
                eat_it(e, fd);
            if (stone == 8)
                e->inventory[fd].stone.linemate =  e->inventory[fd].stone.linemate + 1;
            dprintf(fd, "%s\n", "ok");
		}
	}
	else
	    dprintf(fd, "%s\n", "ko");
	return (0);
}
