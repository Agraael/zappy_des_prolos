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

#endif /* !FTCS_H_ */
