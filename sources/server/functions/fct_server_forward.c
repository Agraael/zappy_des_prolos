/*
** EPITECH PROJECT, 2018
** slt
** File description:
** bit
*/

#include "fcts.h"
#include "struct.h"

void verif_pos(int fd, t_env *e)
{
	if (e->pos_ia[fd].x >= e->infos->map_size.x)
		e->pos_ia[fd].x = 0;
	else if (e->pos_ia[fd].x < 0)
		e->pos_ia[fd].x = e->infos->map_size.x - 1;
	else if (e->pos_ia[fd].y >= e->infos->map_size.y)
		e->pos_ia[fd].y = 0;
	else if (e->pos_ia[fd].y < 0)
		e->pos_ia[fd].y = e->infos->map_size.y - 1;
}

int fct_server_forward(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
//	printf("%lu %lu\n", e->pos_ia[fd].x, e->pos_ia[fd].y);
	if (e->dir[fd] == UP || e->dir[fd] == DOWN) {
		if (e->dir[fd] == UP)
			e->pos_ia[fd].x += 1;
		else
			e->pos_ia[fd].x -= 1;
	} else {
		if (e->dir[fd] == LEFT)
			e->pos_ia[fd].y -= 1;
		else
			e->pos_ia[fd].y += 1;
	}
	verif_pos(fd, e);
	dprintf(fd, "ok\n");
	printf("%d %d\n", e->pos_ia[fd].x, e->pos_ia[fd].y);
	return (0);
}
