/*
** EPITECH PROJECT, 2018
** main
** File description:
** source
*/

#include <iostream>
#include "ParseArgs.hpp"
#include "ConnectToServer.hpp"

int	main(int, char **av)
{
	ParseArgs	parse(av);
	ConnectToServer	client(parse);

	parse.Parser();
	if (parse.checkArgs() == 84)
		return (84);
	client.connectServer();
	return 0;
}