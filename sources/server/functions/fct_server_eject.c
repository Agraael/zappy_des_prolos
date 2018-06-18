/*
** EPITECH PROJECT, 2018
** aa
** File description:
** azd
*/

#include "fcts.h"
#include "struct.h"

static void eject_player(int fd_player, int dir, t_env *e)
{
	if (dir == LEFT) {
		e->pos_ia[fd_player].y -= 1;
		dprintf(fd_player, "eject LEFT\n");
	}
	else if (dir == RIGHT) {
		e->pos_ia[fd_player].y += 1;
		dprintf(fd_player, "eject RIGHT\n");
	}
	else if (dir == UP) {
		e->pos_ia[fd_player].x -= 1;
		dprintf(fd_player, "eject UP\n");
	}
	else if (dir == DOWN) {
		e->pos_ia[fd_player].x += 1;
		dprintf(fd_player, "eject DOWN\n");
	}
	verif_pos(fd_player, e);
}

int fct_server_eject(char *cmd_line, int fd, t_env *e)
{
	int it = 0;

	(void)cmd_line;
	if ((e->infos->map_size.x == 1 && e->infos->map_size.y == 1) ||
	    ((e->dir[fd] == UP || e->dir[fd] == DOWN) && e->infos->map_size.x == 1) || 
		((e->dir[fd] == LEFT || e->dir[fd] == RIGHT) && e->infos->map_size.y == 1)) {
		dprintf(fd, "ko\n");
		return (0);
	}
	for (int x = 0; x < MAX_FD; x++) {
		if (e->fd_type[x] == FD_CLIENT && x != fd &&
		    e->pos_ia[x].x == e->pos_ia[fd].x &&
		    e->pos_ia[x].y == e->pos_ia[fd].y) {
			eject_player(x, e->dir[fd], e);
			it += 1;
		}
	}
	if (it != 0)
		dprintf(fd, "ok\n");
	else
		dprintf(fd, "ko\n");
	return (0);
}
