/*
** EPITECH PROJECT, 2018
** help
** File description:
** source
*/

#include <stdio.h>
#include "help.h"
#include "struct.h"

int	help(char **av, size_t index, infos_t *infos)
{
        (void)av;
        (void)index;
        (void)infos;
	printf("%s\n", FIRSTLINE);
	printf("%s\n", SECONDLINE);
	printf("%s\n", THIRDLINE);
	printf("%s\n", FOURTHLINE);
	printf("%s\n", FIFTHLINE);
	printf("%s\n", SIXTHLINE);
	printf("%s\n", SEVENTHLINE);
	printf("%s\n", EIGHTHLINE);
        return (0);
}