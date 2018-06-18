/*
** EPITECH PROJECT, 2018
** szda
** File description:
** zda
*/

#include "struct.h"

static const t_elevation elevtab[] = {
	{1, 1, 0, 0, 0, 0, 0, 1},
	{2, 1, 1, 1, 0, 0, 0, 2},
	{3, 2, 0, 1, 0, 2, 0, 2},
	{4, 1, 1, 2, 0, 1, 0, 4},
	{5, 1, 2, 1, 3, 0, 0, 4},
	{6, 1, 2, 3, 0, 1, 0, 6},
	{7, 2, 2, 2, 2, 2, 1, 6}
};

int check_players(t_env *e, int fd, stone_t *inventory)
{
	int nbr_players = 0;

	for (int x = 0; x < MAX_FD; x++) {
		if (e->fd_type[x] == FD_CLIENT && x != fd &&
                    e->pos_ia[x].x == e->pos_ia[fd].x &&
                    e->pos_ia[x].y == e->pos_ia[fd].y) {
			nbr_players += 1;
			inventory->linemaute += e->inventory[x].linemaute;
			inventory->deraumere += e->inventory[x].deraumere;
			inventory->sibur += e->inventory[x].sibur;
			inventory->mendiane += e->inventory[x].mendiane;
			inventory->phiras += e->inventory[x].phiras;
			inventory->thystane += e->inventory[x].thystane;
		}
	}
	return (nbr_players);
}

int do_incantation(stone_t *inventory, t_env *e, int fd)
{
	int level = e->vision_field[fd];

	for (int x = 0; x < MAX_FD; x++) {
                if (e->fd_type[x] == FD_CLIENT &&
                    e->pos_ia[x].x == e->pos_ia[fd].x &&
                    e->pos_ia[x].y == e->pos_ia[fd].y) {
			for (; inventory->linemaute > 0; e->inventory[x].linemaute--);
			for (; inventory->deraumere > 0; e->inventory[x].deraumere--);
			for (; inventory->sibur > 0; e->inventory[x].sibur--);
			for (; inventory->mendiane > 0; e->inventory[x].mendiane--);
			for (; inventory->phiras > 0; e->inventory[x].phiras--);
			for (; inventory->thystane > 0; e->inventory[x].thystane--);
			e->vision_field[x] += 1;
			dprintf(fd, "ok congrats you reached lvl %d\n", level);
		}
	}
	return (0);
}

int fct_server_incantation(char *cmd_line, int fd, t_env *e)
{
	int level = e->vision_field[fd];
	stone_t inventory = e->inventory[fd];
	(void)cmd_line;

	if (level >= 8) {
		dprintf(fd, "you can't level up anymore, enjoy the gameplay kappa\n");
		return (0);
	}
	if (check_players(e, fd, &inventory) < elevtab[level].players_around) {
		dprintf(fd, "not enough players mah dude\n");
		return (0);
	} 	
	else if (inventory.linemaute >= elevtab[level].linemate &&
		 inventory.deraumere >= elevtab[level].deraumere &&
		 inventory.sibur >= elevtab[level].sibur &&
		 inventory.mendiane >= elevtab[level].mendiane &&
		 inventory.phiras >= elevtab[level].phiras &&
		 inventory.thystane >= elevtab[level].thystane) {
		return (do_incantation(&inventory, e, fd));
	}
	dprintf(fd, "not enough stones\n");
	return (0);
}
