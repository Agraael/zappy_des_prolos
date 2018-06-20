/*
** EPITECH PROJECT, 2018
** fs
** File description:
** csdz
*/

#include "struct.h"
#include "fcts.h"
#include <string.h>
#include <stdlib.h>


static const t_printtab stonetab[] = {
        {LINEMATE, "linemate"},
        {DERAUMERE, "deraumere"},
        {SIBUR, "sibur"},
        {MENDIANE, "mendiane"},
        {PHIRAS, "phiras"},
        {THYSTAME, "thystame"},

};

static void pose_it(t_env *e , int stone, int fd)
{
    char *place;
    int x = 0;
        if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] == STONE) {
            e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][0] = stone;
            return;
        }
        place = malloc(sizeof(char *) * (strlen(e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y]) + 2));
        while (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]) {
            place[x] = e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x];
            x++;
        }
	place[x] = stone;
	place[x + 1] = '\0';
	e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y] = place;

}

static void verif_if_enought(char * stone, t_env *e, int fd, int sts)
{
    if (strcmp("linemate", stone) == 0 &&  e->inventory[fd].stone.linemate != 0)
        e->inventory[fd].stone.linemate =  e->inventory[fd].stone.linemate - 1;
    else if (strcmp("deraumere", stone) == 0 &&  e->inventory[fd].stone.deraumere != 0)
        e->inventory[fd].stone.deraumere =  e->inventory[fd].stone.deraumere - 1;
    else if (strcmp("sibur", stone ) == 0 &&  e->inventory[fd].stone.sibur != 0)
        e->inventory[fd].stone.sibur =  e->inventory[fd].stone.sibur - 1;
    else if (strcmp("mendiane", stone) == 0 &&  e->inventory[fd].stone.mendiane != 0)
        e->inventory[fd].stone.mendiane =  e->inventory[fd].stone.mendiane - 1;
    else if (strcmp("phiras", stone) == 0 &&  e->inventory[fd].stone.phiras != 0)
        e->inventory[fd].stone.phiras =  e->inventory[fd].stone.phiras - 1;
    else if (strcmp("thystame", stone) == 0 &&  e->inventory[fd].stone.thystame != 0)
        e->inventory[fd].stone.thystame =  e->inventory[fd].stone.thystame - 1;
    else {
        dprintf(fd,"ko\n");
        return;
    }
    pose_it(e, sts, fd);
    dprintf(fd, "ok\n");
}

static int set_it(t_env *e, int fd, const char *subtoken)
{
    for (int i = 0; i < 6; i++) {
            if (strcmp(subtoken, stonetab[i].print) == 0)
                verif_if_enought(stonetab[i].print, e, fd, stonetab[i].stone);
        }
    return (0);
}

int fct_server_setobject(char *cmd_line, int fd, t_env *e)
{
    char *subtoken;

    subtoken = strtok(cmd_line, " ");
    subtoken = strtok(NULL, " ");
    subtoken = strtok(NULL, " ");
    if (subtoken == NULL) {
        dprintf(fd, "ko\n");
        return (0);
    }
    set_it (e, fd, subtoken);
	return (0);
}
