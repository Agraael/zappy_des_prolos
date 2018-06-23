/*
** EPITECH PROJECT, 2018
** bite
** File description:
** za
*/

#include "struct.h"
#include "fcts.h"

int fct_server_inventory(char *cmd_line, int fd, t_env *e)
{
	char buff[4096];
    (void)cmd_line;

	sprintf(buff,"[%s %i,%s %i,%s %i,%s %i,%s %i,%s %i]\n", "linemate",
		(int)e->inventory[fd].stone.linemate, "deraumere",
		(int)e->inventory[fd].stone.deraumere,"sibur",
		(int)e->inventory[fd].stone.sibur, "mendiane",
		(int)e->inventory[fd].stone.mendiane,"phiras",
		(int)e->inventory[fd].stone.phiras, "thystane",
		(int)e->inventory[fd].stone.thystame);
	dprintf(fd,"%s\n", buff);

	return (0);
}
