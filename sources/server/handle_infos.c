/*
** EPITECH PROJECT, 2018
** init_info
** File description:
** source
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "struct.h"
#include "macro.h"

bool	check_validity(infos_t *infos)
{
	if (infos->frequence == 0 || infos->clients_nb == 0
	|| infos->clients_nb > 255
	|| infos->map_size.x == 0 || infos->map_size.x > 100
	|| infos->map_size.y == 0 || infos->map_size.y > 100
	|| (infos->port < 1024 || infos->port > 65535)
	|| infos->team_names == NULL) {
		dprintf(2, "%s\n", ARGS_PROBLEM);
		return false;
	}
	//printf("%d\n", infos->map_size.y);
	return true;
}

void	init_default_info(infos_t **infos)
{
	(*infos)->port = 0;
	(*infos)->map_size.x = 0;
	(*infos)->map_size.y = 0;
	(*infos)->team_names = NULL;
	(*infos)->clients_nb = 0;
	(*infos)->frequence = 100;
}
