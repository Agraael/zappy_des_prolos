/*
** EPITECH PROJECT, 2018
** struct
** File description:
** header
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

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

#endif /* !STRUCT_H_ */
