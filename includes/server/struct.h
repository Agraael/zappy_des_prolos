/*
** EPITECH PROJECT, 2018
** struct
** File description:
** header
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

#include <unistd.h>

typedef struct	vec_s {
	size_t	x;
	size_t	y;
}		vec_t;

typedef struct	info_s {
	size_t	port;
	vec_t	map_size;
	char	**team_names;
	size_t	clients_nb;
	size_t	frequence;
}		infos_t;

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
