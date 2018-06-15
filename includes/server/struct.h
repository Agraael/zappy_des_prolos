/*
** EPITECH PROJECT, 2018
** struct
** File description:
** header
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#define STONE 7
#define FOOD 6
#define LINEMATE 0
#define DERAUMERE 1
#define SIBUR 2
#define MENDIANE 3
#define PHIRAS 4
#define THYSTAME 5

#define FD_FREE 0
#define FD_CLIENT 1
#define FD_SERVER 2
#define MAX_FD 255
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

typedef struct s_stonetab {
	int id;
	int stone;
}	       t_stonetab;

typedef struct s_printtab {
	int stone;
	char *print;
}              t_printtab;

typedef struct	vec_s {
	int	x;
	int	y;
}		vec_t;

typedef struct s_infoteam {
	char *name;
	int players_remaining;
} t_infoteam;

typedef struct	info_s {
	size_t	port;
	vec_t	map_size;
	t_infoteam *team_names;
	size_t	clients_nb;
	size_t	frequence;
	char	***map;
}		infos_t;
// anat

typedef void(*fct)();

typedef struct s_env
{
        char fd_type[MAX_FD];
        fct fct_read[MAX_FD];
        fct fct_write[MAX_FD];
	int has_team[MAX_FD];
        infos_t *infos;
	int dir[MAX_FD];
	int vision_field[MAX_FD];
	vec_t pos_ia[MAX_FD];
} t_env;

typedef struct s_serv_functions {
        char *str;
        int (*pts)(char *, int, t_env *);
        int length;
} t_serv_functions;
	
//fin
typedef struct	stones_s {
	size_t	linemaute;
	size_t	deraumere;
	size_t	sibur;
	size_t	mendiane;
	size_t	phiras;
	size_t	thystane;
}		stone_t;

typedef struct  client_s {
	size_t	time_units;
	stone_t	stones;
}		client_t;

typedef	struct	s_functions {
	char	*str;
	int	(*func)(char **, size_t, infos_t **);
}		t_functions;

#endif /* !STRUCT_H_ */
