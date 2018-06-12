/*
** EPITECH PROJECT, 2018
** main
** File description:
** source
*/

#include "../../includes/server/help.h"

void    help()
{
	printf("%s\n", FIRSTLINE);
	printf("%s\n", SECONDLINE);
	printf("%s\n", THIRDLINE);
	printf("%s\n", FOURTHLINE);
}

int     main(int ac, char **av)
{
        (void)ac;
        (void)av;
        help();
}