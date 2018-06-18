/*
** EPITECH PROJECT, 2018
** slt
** File description:
** bite
*/

#include "struct.h"

int fct_server_connectnbr(char *cmd_line, int fd, t_env *e)
{
	int team_nbr = e->has_team[fd];

	(void)cmd_line;
	dprintf(fd, e->infos->team_names[team_nbr].name);
	dprintf(fd, " %d\n", e->infos->team_names[team_nbr].players_remaining);
	return (0);
}
