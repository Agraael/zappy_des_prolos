/*
** EPITECH PROJECT, 2018
** bite
** File description:
** za
*/

#include "struct.h"

int fct_server_inventory(char *cmd_line, int fd, t_env *e)
{
	char buff[4096];
	
	sprintf(buff,"[%s %i,%s %i,%s %i,%s %i,%s %i,%s %i]\n", "linemate",
		(int)e->inventory[fd].linemaute, "deraumere",
		(int)e->inventory[fd].deraumere,"sibur",
		(int)e->inventory[fd].sibur, "mendiane",
		(int)e->inventory[fd].mendiane,"phiras",
		(int)e->inventory[fd].phiras, "thystane",
		(int)e->inventory[fd].thystame);
	dprintf(fd,"%s", buff);
	(void)cmd_line;
	return (0);
}
