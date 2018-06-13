/*
** EPITECH PROJECT, 2018
** utils
** File description:
** fcts
*/

#include "struct.h"
#include <string.h>
#include <stdlib.h>

char *epur(char *test)
{
	char *new = NULL;
	int x = 0;
	int y = 0;
	int i = 0;

	for (; test[i] && test[i] != '\r' && test[i] != '\n'; i++);
	test[i] = '\0';
	new = malloc(sizeof(char) * strlen(test) + 1);
	while (test[x]) {
		new[y] = test[x];
		x++;
		(test[x] &&
			(test[x] == ' ' || test[x] == '\t') && (x - 1 >= 0) &&
			(test[x - 1] == ' ' || test[x - 1] == '\t')) ?
			y = y : y++;
	}
	new[y] = '\0';
	return (new);
}

/*
void print_to_user(t_chan_infos *server, char *cmd_line, t_env *e)
{
	int client_fd = 0;

	for (int i = 0; i < 255; i++) {
		if (server->members_in[i]) {
			client_fd = find_good_fd(server->members_in[i],
						server->nicknames_in[i], e);
			dprintf(client_fd, "%s\r\n", cmd_line);
		}
	}
	}*/
