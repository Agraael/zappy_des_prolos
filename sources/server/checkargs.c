/*
** EPITECH PROJECT, 2018
** checkargs
** File description:
** source
*/

#include "help.h"
#include "struct.h"

/* static const	t_functions tab[] = {
	{"-p", &client_user},
	{"-x", &client_password},
	{"-y", &client_cwd},
	{"-n", &client_cdup},
	{"-c", &client_quit},
	{"-f", &client_dele},
}; */

int     checkargs(int ac, char **av)
{
	if (ac == 1)
		return (84);
	(void)av;
	return (0);        
}