/*
** EPITECH PROJECT, 2018
** server
** File description:
** pointc
*/

#include "struct.h"
#include <string.h>
#include <stdlib.h>

void client_read(t_env *e, int fd)
{
	int r;
	char buf[4096];
	char **line;

	r = read(fd, buf, 4096);
	if (r > 0) {
		buf[r] = '\0';
		line = my_str_to_wordtab(buf, '\n');
		for (int x = 0; line[x]; line++) {
			line[x] = epur(line[x]);
			printf("->%s - %d\n", line[x], fd);
			//  assign_to_function(e, fd, line[x]);
		}
	}
	else {
		close(fd);
		e->fd_type[fd] = FD_FREE;
	}
}

static void add_client(t_env *e, int s)
{
	int cs;
	struct sockaddr_in client_sin;
	socklen_t client_sin_len;

	client_sin_len = sizeof(client_sin);
	cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
	e->fd_type[cs] = FD_CLIENT;
	e->fct_read[cs] = client_read;
	e->fct_write[cs] = NULL;
}

static void server_read(t_env *e, int fd)
{
	add_client(e, fd);
}

static void add_server(t_env *e)
{
	int s;
	struct sockaddr_in sin;

	s = socket(PF_INET, SOCK_STREAM, 0);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(e->infos->port);
	sin.sin_addr.s_addr = INADDR_ANY;
	bind(s, (struct sockaddr *)&sin, sizeof(sin));
	listen(s, 42);
	e->fd_type[s] = FD_SERVER;
	e->fct_read[s] = server_read;
	e->fct_write[s] = NULL;
}

void create_server(infos_t *infos)
{
	t_env e;

	memset(e.fd_type, FD_FREE, MAX_FD);
	e.infos = infos;
	add_server(&e);
	loop_server(&e);
}
