/*
** EPITECH PROJECT, 2018
** ptn
** File description:
** slt
*/

#include "struct.h"
#include "math.h"

static void print_diagonals(t_env *e, int x, int fd)
{
	int angle = 0;

	if ((e->infos->map_size.y - e->pos_ia[fd].y) + e->pos_ia[x].y > (e->pos_ia[fd].y - e->pos_ia[x].y)) {
		if ((e->infos->map_size.x - e->pos_ia[fd].x) + e->pos_ia[x].x > (e->pos_ia[fd].x - e->pos_ia[x].x))
			angle = 6;
		else
			angle = 4;
	}
	else {
		if ((e->infos->map_size.x - e->pos_ia[fd].x) + e->pos_ia[x].x > (e->pos_ia[fd].x - e->pos_ia[x].x))
			angle = 8;
		else
			angle = 2;
	}
	dprintf(x, "message %d, text\n", angle);
}

static void print_broadcast(t_env *e, int x, int fd)
{
	int angle = 0;
	if (e->pos_ia[x].x == e->pos_ia[fd].x && e->pos_ia[x].y == e->pos_ia[fd].y) {
		dprintf(x, "message 0, text\n");
		return;
	}
	if (e->pos_ia[x].x == e->pos_ia[fd].x) {
		if ((e->infos->map_size.y - e->pos_ia[fd].y) + e->pos_ia[x].y > (e->pos_ia[fd].y - e->pos_ia[x].y))
			angle = 7;
		else
			angle = 3;
	}
	else if (e->pos_ia[x].y == e->pos_ia[fd].y) {
		if ((e->infos->map_size.x - e->pos_ia[fd].x) + e->pos_ia[x].x > (e->pos_ia[fd].x - e->pos_ia[x].x))
                        angle = 5;
                else
                        angle = 1;
	}
	else
		return (print_diagonals(e, x, fd));
	dprintf(x, "message %d, text\n", angle);
}

int fct_server_broadcast(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	for (int x = 0; x < MAX_FD; x++) {
		if (e->fd_type[x] == FD_CLIENT && x != fd) {
			print_broadcast(e, x, fd);
		}
	}
	return (0);
}
