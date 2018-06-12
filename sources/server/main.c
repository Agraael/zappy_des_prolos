/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <stdio.h>
#include "../../includes/server/help.h"

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
        (void)ac;
        (void)av;
	help();
}