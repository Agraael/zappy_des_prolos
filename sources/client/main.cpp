/*
** EPITECH PROJECT, 2018
** main
** File description:
** source
*/

#include <iostream>
#include "ParseArgs.hpp"
#include "CommunicateToServer.hpp"

int	main(int, char **av)
{
	ParseArgs	*parse = new ParseArgs(av);
	serverSpace::CommunicateToServer	client(parse);

	parse->Parser();
	if (parse->checkArgs() == 84)
		return (84);
	client.connectToServer();
	return 0;
}