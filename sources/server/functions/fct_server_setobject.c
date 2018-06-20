/*
** EPITECH PROJECT, 2018
** fs
** File description:
** csdz
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

};

static void pose_it(t_env *e , int stone)
{
    for (int x = 0; e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x]; x++) {
        if (e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x] == STONE) {
            e->infos->map[e->pos_ia[fd].x][e->pos_ia[fd].y][x] = stone;
        }
    }
}

static void verif_if_enought(char * stone, t_env *e, int fd, int sts)
{
    if (strcmp("linemate", stone) == 0)
        e->inventory[fd].stone.linemate =  e->inventory[fd].stone.linemate - 1;
    else if (strcmp("deraumere", stone) == 0)
        e->inventory[fd].stone.deraumere =  e->inventory[fd].stone.deraumere - 1;
    else if (strcmp("sibur", stone ) == 0)
        e->inventory[fd].stone.sibur =  e->inventory[fd].stone.sibur - 1;
    elseif (strcmp("mendiane", stone) == 0)
        e->inventory[fd].stone.mendiane =  e->inventory[fd].stone.mendiane - 1;
    if (strcmp("phiras", stone) == 0)
        e->inventory[fd].stone.phiras =  e->inventory[fd].stone.phiras - 1;
    if (strcmp("thystame", stone) == 0)
        e->inventory[fd].stone.thystame =  e->inventory[fd].stone.thystame - 1;
    else
        return ;
    pose_it(e, sts);
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
    dprintf(fd, "ok\n");
	return (0);
}
