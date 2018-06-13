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

typedef struct s_stonetab {
	int id;
	int stone;
}	       t_stonetab;

typedef	struct	s_functions {
	char	*str;
	void	(*func)(char *);
}		t_functions;

typedef struct	vector_s {
	int	x;
	int	y;
}		vec_t;

typedef struct	info_s {
	int	port;
	vec_t	map_size;
	char	**team_names;
	int	clients_nb;
	int	frequence;
	char	**map;
}		infos_t;
// anat

typedef void(*fct)();

typedef struct s_env
{
        char fd_type[MAX_FD];
        fct fct_read[MAX_FD];
        fct fct_write[MAX_FD];
        infos_t *infos;
        //int is_logged[MAX_FD];                                                                         
        //char *nickname[MAX_FD];                                                                        
        //char *user[MAX_FD];                                                                            
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

int loop_server(t_env *e);
char *epur(char *test);
char **my_str_to_wordtab(char *str, char delim);
void create_server(infos_t *infos);
void generate_map(infos_t *infos_game);

#endif /* !STRUCT_H_ */
