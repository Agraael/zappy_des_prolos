
/*
** EPITECH PROJECT, 2018
** server
** File description:
** pointc
*/

#include "struct.h"
#include "fcts.h"
#include <string.h>
#include <stdlib.h>

static const t_serv_functions tab[] = {
        {"forward", &fct_server_forward, 7, 7},
        {"right", &fct_server_right, 5, 7},
        {"left", &fct_server_left, 4, 7},
        {"look", &fct_server_look, 4, 7},
        {"inventory", &fct_server_inventory, 9, 1},
        {"broadcast text", &fct_server_broadcast, 14, 7},
        {"connect_nbr", &fct_server_connectnbr, 11, 0},
        {"fork", &fct_server_fork, 4, 42},
        {"eject", &fct_server_eject, 5, 7},
        {"take object", &fct_server_take, 11, 7},
        {"set object", &fct_server_setobject, 10, 7},
		{"team-name", &fct_server_teamname, 9, 0},
		{"incantation", &fct_server_incantation, 11, 300},
		{"quit", &fct_server_quit, 4, 0}
};

static int assign_to_function(t_env *e, int fd, char *buff)
{
	t_passing arg;

	if (e->has_team[fd] == -1) {
		if (strncmp(tab[11].str, buff, tab[11].length) == 0)
                        return (tab[11].pts(buff, fd, e));
		else {
			dprintf(fd, "ko join a team first, with team-name name\n");
			return (0);
		}	
	}
	for (int i = 0; i != 14; i++) {
		if (strncmp(tab[i].str, buff, tab[i].length) == 0) {
			arg.e = e;
			arg.fd = fd;
			arg.buff = buff;
			arg.time =  time;
			push(tab[i].pts, &arg);
			return (0);
		}
	}
	return (0);
}


void client_read(t_env *e, int fd)
{
	int r;
	char buf[4096];
	char **line;

	r = read(fd, buf, 4096);
	if (r > 0) {
		buf[r] = '\0';
		line = my_str_to_wordtab(buf, '\n');
		for (int x = 0; line[x] && x < 10; line++) {
			line[x] = epur(line[x]);
			printf("->%s - %d\n", line[x], fd);
			assign_to_function(e, fd, line[x]);
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
	e->pos_ia[cs] = create_random_pos(e->infos->map_size);
	e->vision_field[cs] = 1;
	e->has_team[cs] = -1;
	e->dir[cs] = LEFT;
	e->inventory[cs].food = 1260.00;

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
    bind(s, (struct sockaddr *) &sin, sizeof(sin));
    listen(s, 42);
    e->fd_type[s] = FD_SERVER;
    e->fct_read[s] = server_read;
    e->fct_write[s] = NULL;
    for (int i = 0; e->infos->team_names[i].name; i++)
        e->infos->team_names[i].players_remaining = e->infos->clients_nb;
}

void create_server(infos_t *infos)
{
	t_env e;

	memset(e.fd_type, FD_FREE, MAX_FD);
	memset(e.inventory, 0, (size_t)MAX_FD * sizeof(inventory_t));
	e.infos = infos;
	add_server(&e);
	loop_server(&e);
}
