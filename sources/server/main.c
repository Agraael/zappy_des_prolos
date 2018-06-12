/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <stdio.h>
#include "help.h"
#include "fcts.h"

void    help()
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
}