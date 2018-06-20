/*
** EPITECH PROJECT, 2018
** fct
** File description:
** server quit
*/

#include "fcts.h"
#include "struct.h"
#include <stdlib.h>
#include <string.h>

static void drop_stone(t_env *e, int fd, int stone)
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

static void drop_inventory(t_env *e, int fd)
{
	for (; e->inventory[fd].stone.linemate > 0; e->inventory[fd].stone.linemate--)
		drop_stone(e, fd, LINEMATE);
	for (; e->inventory[fd].stone.deraumere > 0; e->inventory[fd].stone.deraumere--)
		drop_stone(e, fd, DERAUMERE);
	for (; e->inventory[fd].stone.sibur > 0; e->inventory[fd].stone.sibur--)
		drop_stone(e, fd, SIBUR);
	for (; e->inventory[fd].stone.mendiane > 0; e->inventory[fd].stone.mendiane--)
		drop_stone(e, fd, MENDIANE);
	for (; e->inventory[fd].stone.phiras > 0; e->inventory[fd].stone.phiras--)
		drop_stone(e, fd, PHIRAS);
	for (; e->inventory[fd].stone.thystame > 0; e->inventory[fd].stone.thystame--)
		drop_stone(e, fd, PHIRAS);
}

int fct_server_quit(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	dprintf(fd, "you died of starvation/ volunteer leaving. your inventory is dropped on the ground\n");
	drop_inventory(e, fd);
	close(fd);
        e->fd_type[fd] = FD_FREE;
        return (0);
}
