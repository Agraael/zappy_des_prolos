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

int check_players(t_env *e, int fd, inventory_t *inventory)
{
	int nbr_players = 0;

	for (int x = 0; x < MAX_FD; x++) {
		if (e->fd_type[x] == FD_CLIENT &&
                    e->pos_ia[x].x == e->pos_ia[fd].x &&
                    e->pos_ia[x].y == e->pos_ia[fd].y) {
			nbr_players += 1;
			inventory->stone.linemate += e->inventory[x].stone.linemate;
			inventory->stone.deraumere += e->inventory[x].stone.deraumere;
			inventory->stone.sibur += e->inventory[x].stone.sibur;
			inventory->stone.mendiane += e->inventory[x].stone.mendiane;
			inventory->stone.phiras += e->inventory[x].stone.phiras;
			inventory->stone.thystame += e->inventory[x].stone.thystame;
		}
	}
	return (nbr_players);
}

int do_incantation(inventory_t *inventory, t_env *e, int fd)
{
	int level = e->vision_field[fd];

	for (int x = 0; x < MAX_FD; x++) {
                if (e->fd_type[x] == FD_CLIENT &&
                    e->pos_ia[x].x == e->pos_ia[fd].x &&
                    e->pos_ia[x].y == e->pos_ia[fd].y) {
			for (; inventory->stone.linemate > 0; e->inventory[x].stone.linemate--);
			for (; inventory->stone.deraumere > 0; e->inventory[x].stone.deraumere--);
			for (; inventory->stone.sibur > 0; e->inventory[x].stone.sibur--);
			for (; inventory->stone.mendiane > 0; e->inventory[x].stone.mendiane--);
			for (; inventory->stone.phiras > 0; e->inventory[x].stone.phiras--);
			for (; inventory->stone.thystame > 0; e->inventory[x].stone.thystame--);
			e->vision_field[x] += 1;
			dprintf(fd, "ok congrats you reached lvl %d\n", level);
		}
	}
	return (0);
}

int fct_server_incantation(char *cmd_line, int fd, t_env *e)
{
	int level = e->vision_field[fd];
	inventory_t inventory = e->inventory[fd];
	(void)cmd_line;

	if (level >= 8) {
		dprintf(fd, "you can't level up anymore, enjoy the gameplay kappa\n");
		return (0);
	}
	if (check_players(e, fd, &inventory) < elevtab[level].players_around) {
		dprintf(fd, "not enough players mah dude\n");
		return (0);
	} 	
	else if (inventory.stone.linemate >= elevtab[level].linemate &&
		 inventory.stone.deraumere >= elevtab[level].deraumere &&
		 inventory.stone.sibur >= elevtab[level].sibur &&
		 inventory.stone.mendiane >= elevtab[level].mendiane &&
		 inventory.stone.phiras >= elevtab[level].phiras &&
		 inventory.stone.thystame >= elevtab[level].thystane) {
		return (do_incantation(&inventory, e, fd));
	}
	dprintf(fd, "not enough stones\n");
	return (0);
}
