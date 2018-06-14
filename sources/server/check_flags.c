/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "tab.h"
#include "macro.h"

int	check_port(char **av, size_t index, infos_t **infos)
{
       	static int	here = 0;

	++here;
	if (is_str_digit(av[index + 1]) == false || here == 2) {
		dprintf(2, "%s\n", WRONG_PORT);
		return 84;
	}
	else if (av[index + 2] == NULL) {
		(*infos)->port = atoi(av[index + 1]);
		return 0;
	}
	for (size_t n = 0; g_tab[n].str != NULL; ++n) {
		if (strcmp(av[index + 2], g_tab[n].str) == 0) {
			(*infos)->port = atoi(av[index + 1]);
			return 0;
		}
	}
	dprintf(2, "%s\n", WRONG_PORT);	
	return 84;
}

int	check_width(char **av, size_t index, infos_t **infos)
{
       	static int	here = 0;

	++here;
	if (is_str_digit(av[index + 1]) == false || here == 2) {
		dprintf(2, "%s\n", WRONG_WIDTH);
		return 84;
	}
	else if (av[index + 2] == NULL) {
		(*infos)->map_size.x = atoi(av[index + 1]);
		return 0;
	}
	for (size_t n = 0; g_tab[n].str != NULL; ++n) {
		if (strcmp(av[index + 2], g_tab[n].str) == 0) {
			(*infos)->map_size.x = atoi(av[index + 1]);
			return 0;
		}
	}
	dprintf(2, "%s\n", WRONG_WIDTH);	
	return 84;
}

int	check_height(char **av, size_t index, infos_t **infos)
{
       	static int	here = 0;

	++here;
	if (is_str_digit(av[index + 1]) == false || here == 2) {
		dprintf(2, "%s\n", WRONG_HEIGHT);
		return 84;
	}
	else if (av[index + 2] == NULL) {
		(*infos)->map_size.y = atoi(av[index + 1]);
		return 0;
	}
	for (size_t n = 0; g_tab[n].str != NULL; ++n) {
		if (strcmp(av[index + 2], g_tab[n].str) == 0) {
			(*infos)->map_size.y = atoi(av[index + 1]);
			return 0;
		}
	}
	dprintf(2, "%s\n", WRONG_HEIGHT);
	return 84;
}

char	**create_tab(char **av, int size, int index)
{
	int	i = 0;
	char	**new_tab = malloc(sizeof(char *) * (size + 1));

	if (new_tab == NULL) {
		dprintf(2, "%s\n", WRONG_NAMES);
		return NULL;
	}
	for (; i < size; ++i) {
		new_tab[i] = strdup(av[index + i]);
		if (new_tab[i] == NULL) {
			dprintf(2, "%s\n", WRONG_NAMES);
			return NULL;
		}
	}
	new_tab[i] = NULL;
	return (new_tab);
}

int	check_names(char **av, size_t index, infos_t **infos)
{
	static int	here = 0;
	int		count = 0;
	bool		exist = false;

	(void)infos;
	++here;
	if (av[index + 1] == NULL || here == 2) {
		dprintf(2, "%s\n", WRONG_NAMES);
		return 84;
	}
	if (av[index + 2] == NULL) {
		(*infos)->team_names = create_tab(av, 1, index + 1);
		return 0;
	}
	for (size_t i = 1; av[index + i] != NULL; ++i) {
		exist = false;
		for (size_t n = 0; g_tab[n].str != NULL; ++n) {
			if (strcmp(av[index + i], g_tab[n].str) == 0)
				exist = true;
		}
		if (exist == false)
			++count;
		else
			(*infos)->team_names = create_tab(av, count, index + 1);
	}
	(*infos)->team_names = create_tab(av, count, index + 1);
	return (0);
}

int	check_client_nb(char **av, size_t index, infos_t **infos)
{
       	static int	here = 0;

	++here;
	if (is_str_digit(av[index + 1]) == false || here == 2) {
		dprintf(2, "%s\n", WRONG_CLIENT_NB);
		return 84;
	}
	else if (av[index + 2] == NULL) {
		(*infos)->clients_nb = atoi(av[index + 1]);
		return 0;
	}
	for (size_t n = 0; g_tab[n].str != NULL; ++n) {
		if (strcmp(av[index + 2], g_tab[n].str) == 0) {
			(*infos)->clients_nb = atoi(av[index + 1]);
			return 0;
		}
	}
	dprintf(2, "%s\n", WRONG_CLIENT_NB);
	return 84;
}