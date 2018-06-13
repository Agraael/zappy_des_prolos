/*
** EPITECH PROJECT, 2018
** loop
** File description:
** server
*/

#include "struct.h"

int loop_server(t_env *e)
{
	int i;
	int fd_max;
	fd_set fd_read;

	while (1) {
		FD_ZERO(&fd_read);
		fd_max = 0;
		for (i = 0; i < MAX_FD; i++)
			if (e->fd_type[i] != FD_FREE) {
				FD_SET(i, &fd_read);
				fd_max = i;
			}
		if (select(fd_max + 1, &fd_read, NULL, NULL, NULL) == -1)
			return (84);
		for (i = 0; i < MAX_FD; i++)
			if (FD_ISSET(i, &fd_read))
				e->fct_read[i](e, i);
	}
	return (0);
}
