/*
** EPITECH PROJECT, 2018
** slt
** File description:
** snt
*/

#include "struct.h"
#include "fcts.h"

int fct_server_left(char *cmd_line, int fd, t_env *e)
{
	(void)cmd_line;
	if (e->dir[fd] == UP || e->dir[fd] == DOWN) {
		if (e->dir[fd] == UP)
			e->dir[fd] = LEFT;
		else
			e->dir[fd] = RIGHT;
	} else {
		if (e->dir[fd] == LEFT)
			e->dir[fd] = DOWN;
		else
			e->dir[fd] = UP;
	}
	dprintf(fd, "ok\n");
	return (0);
}
