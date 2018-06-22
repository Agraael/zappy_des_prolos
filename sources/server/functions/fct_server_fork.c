/*
** EPITECH PROJECT, 2018
** fqzd
** File description:
** fzqd
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "struct.h"

static char *getip()
{
	char hostbuffer[256];
	char *ipbuffer;
	struct hostent *host_entry;

	gethostname(hostbuffer, sizeof(hostbuffer));
	host_entry = gethostbyname(hostbuffer);
	ipbuffer = inet_ntoa(*((struct in_addr*)
			host_entry->h_addr_list[0]));
	return (ipbuffer);
}

int fct_server_fork(char *cmd_line, int fd, t_env *e)
{
	int err;
	int i = e->has_team[fd];
	char *port = malloc(sizeof(char) * 10);
	int x = sprintf(port, "%ld", e->infos->port);
	char *argv[8] = { "kaka", "-p", port, "-n", e->infos->team_names[i].name, "-h", getip(), 0 };

	(void)cmd_line;
	if (x < 0)
		return (0);
	if (fork() == 0) {
		err = execve("./zappy_ai", argv, NULL);
		if (err == -1)
			return (0);
	}
	dprintf(fd, "ok\n");
	return (0);
}
