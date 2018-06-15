/*
** EPITECH PROJECT, 2018
** fct
** File description:
** teamna*
*/

#include "struct.h"
#include <string.h>
#include <stdlib.h>

static t_infoteam add_teammember(t_infoteam team, int fd, t_env *e)
{
	team.players_remaining -= 1;
	e->has_team[fd] = 1;
	dprintf(fd, "%d (players left in team)\n", team.players_remaining);
	dprintf(fd, "%d %d (map size x y)\n", e->infos->map_size.x, e->infos->map_size.y);
	return (team);
}

static int is_num(char *cmd_line)
{
	for (int i = 0; cmd_line[i]; i++) {
		if (!(cmd_line[i] >= '0' && cmd_line[i] <= '9'))
			return (1);
	}
	return (0);
}

int fct_server_teamname(char *cmd_line, int fd, t_env *e)
{
	while (cmd_line[0] != '\0'  && cmd_line[0] != ' ')
		cmd_line++;
	if (!cmd_line || cmd_line[0] == '\0')
		return (0);
	cmd_line++;
	for (int i = 0; e->infos->team_names[i].name; i++) {
		if (strcmp(e->infos->team_names[i].name, cmd_line) == 0 ||
		    (is_num(cmd_line) == 0 && i == atoi(cmd_line)))
			e->infos->team_names[i] = add_teammember(e->infos->team_names[i], fd, e);
	}
	return (0);
}
