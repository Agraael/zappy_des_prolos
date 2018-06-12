/*
** EPITECH PROJECT, 2018
** struct
** File description:
** header
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

#include <unistd.h>

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

#endif /* !STRUCT_H_ */
