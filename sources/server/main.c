/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <stdio.h>
#include "help.h"
#include "fcts.h"
#include "struct.h"

void    help(void)
{
	printf("%s\n", FIRSTLINE);
	printf("%s\n", SECONDLINE);
	printf("%s\n", THIRDLINE);
	printf("%s\n", FOURTHLINE);
	printf("%s\n", FIFTHLINE);
	printf("%s\n", SIXTHLINE);
	printf("%s\n", SEVENTHLINE);
	printf("%s\n", EIGHTHLINE);
}

int	main(int ac, char **av)
{
	if (checkargs(ac, av) == 84)
		return (84);
	help();
	infos_t infos;
	infos.map_size.x = 10;
	infos.map_size.y = 10;
	infos.port = 4227;
	generate_map(&infos);
	create_server(&infos);
}
