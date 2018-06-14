/*
** EPITECH PROJECT, 2018
** checkargs
** File description:
** source
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#include "struct.h"
#include "fcts.h"
#include "macro.h"
#include "tab.h"

int	check_freq(char **av, size_t index, infos_t **infos)
{
	static int	here = 0;

	++here;
	if (is_str_digit(av[index + 1]) == false || here == 2) {
		dprintf(2, "%s\n", WRONG_FREQ);
		return 84;
	}
	else if (av[index + 2] == NULL) {
		(*infos)->frequence = atoi(av[index + 1]);
		return 0;
	}
	for (size_t n = 0; g_tab[n].str != NULL; ++n) {
		if (strcmp(av[index + 2], g_tab[n].str) == 0) {
			(*infos)->frequence = atoi(av[index + 1]);
			return 0;
		}
	}
	dprintf(2, "%s\n", WRONG_FREQ);	
	return 84;
}

int     checkargs(int ac, char **av, infos_t *infos)
{
	if (ac == 1)
		return (84);
	init_default_info(&infos);
	for (size_t i = 0; av[i] != NULL; ++i) {
		for (size_t n = 0; g_tab[n].str != NULL; ++n) {
			if (strcmp(av[i], g_tab[n].str) == 0) {
				if (g_tab[n].func(av, i, &infos) == 84)
					return 84;
			}
		}
	}
	if (!(check_validity(infos)))
		return 84;
	for (int i = 0; infos->team_names[i]; ++i) {
		printf("%s\n", infos->team_names[i]);
	}
	return (0);
}