/*
** EPITECH PROJECT, 2018
** fcts
** File description:
** 
*/

#ifndef FTCS_H_
	#define FTCS_H_

#include <stdbool.h>
#include "struct.h"

int	checkargs(int, char **, infos_t *);
int	check_port(char **, size_t, infos_t **);
int	check_width(char **, size_t, infos_t **);
int	check_height(char **, size_t, infos_t **);
int	check_names(char **, size_t, infos_t **);
int	check_client_nb(char **, size_t, infos_t **);
int	check_freq(char **, size_t, infos_t **);
int	help(char **, size_t, infos_t **);
void	init_default_info(infos_t **);
bool    is_str_digit(char *);
bool	check_validity(infos_t *);
void print_case(int fd, t_env *e, vec_t pos);
vec_t create_random_pos(vec_t map_size);
void print_lines_left(int fd, t_env *e, int nbr_of_lines);
void print_lines_right(int fd, t_env *e, int nbr_of_lines);
void print_lines_up(int fd, t_env *e, int nbr_of_lines);
void print_lines_down(int fd, t_env *e, int nbr_of_lines);
void verif_pos(int fd, t_env *e);
int fct_server_incantation(char *cmd_line, int fd, t_env *e);
int fct_server_forward(char *cmd_line, int fd, t_env *e);
int fct_server_right(char *cmd_line, int fd, t_env *e);
int fct_server_left(char *cmd_line, int fd, t_env *e);
int fct_server_look(char *cmd_line, int fd, t_env *e);
int fct_server_inventory(char *cmd_line, int fd, t_env *e);
int fct_server_broadcast(char *cmd_line, int fd, t_env *e);
int fct_server_connectnbr(char *cmd_line, int fd, t_env *e);
int fct_server_fork(char *cmd_line, int fd, t_env *e);
int fct_server_eject(char *cmd_line, int fd, t_env *e);
int fct_server_take(char *cmd_line, int fd, t_env *e);
int fct_server_setobject(char *cmd_line, int fd, t_env *e);
int loop_server(t_env *e);
char *epur(char *test);
char **my_str_to_wordtab(char *str, char delim);
void create_server(infos_t *infos);
void generate_map(infos_t *infos_game);

#endif /* !FTCS_H_ */
