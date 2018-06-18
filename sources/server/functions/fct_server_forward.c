/*
** EPITECH PROJECT, 2018
** slt
** File description:
** bit
*/

#include "struct.h"

int fct_server_forward(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	if (e->dir[fd] == UP || e->dir[fd] == DOWN) {
		if (e->dir[fd] == UP) {
			if (e->pos_ia[fd].x < e->infos->map_size.x - 1)
				e->pos_ia[fd].x += 1;
			else
				e->pos_ia[fd].x = 0;
		}
		else {
			if (e->pos_ia[fd].x > 0)
				e->pos_ia[fd].x -= 1;
			else
				e->pos_ia[fd].x = e->infos->map_size.x - 1;
		}
	} else {
		if (e->dir[fd] == LEFT) {
			if (e->pos_ia[fd].y > 0)
				e->pos_ia[fd].y -= 1;
			else
				e->pos_ia[fd].y = e->infos->map_size.y - 1;
		}
		else {
			if (e->pos_ia[fd].y < e->infos->map_size.y - 1)
				e->pos_ia[fd].y += 1;
			else
				e->pos_ia[fd].y = 0;
		}
	}
	return (0);
}
