/*
** EPITECH PROJECT, 2018
** fcts
** File description:
** 
*/

#ifndef FTCS_H_
	#define FTCS_H_

#include "struct.h"

int	checkargs(int, char **);
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

#endif /* !FTCS_H_ */
