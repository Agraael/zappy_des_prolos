/*
** EPITECH PROJECT, 2018
** ct
** File description:
** fz
*/

#include "struct.h"

int fct_server_right(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	if (e->dir[fd] == UP || e->dir[fd] == DOWN) {
		if (e->dir[fd] == UP)
			e->dir[fd] = RIGHT;
		else
			e->dir[fd] = LEFT;
	} else {
		if (e->dir[fd] == LEFT)
			e->dir[fd] = UP;
		else
			e->dir[fd] = DOWN;
	}
	return (0);
}
