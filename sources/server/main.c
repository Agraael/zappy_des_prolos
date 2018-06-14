/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <stdlib.h>
#include <stdio.h>
#include "fcts.h"
#include "struct.h"

int	main(int ac, char **av)
{
	infos_t	*infos = malloc(sizeof(infos_t));

	if (infos == NULL || checkargs(ac, av, infos) == 84)
		return (84);
	printf("i create a map of 10x10 and launch the server in port %lu\n", infos->port);
	generate_map(infos);
	create_server(infos);
}