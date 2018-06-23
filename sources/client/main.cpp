/*
** EPITECH PROJECT, 2018
** main
** File description:
** source
*/

#include <iostream>
#include <ZappyAi.hpp>
#include "ParseArgs.hpp"
#include "CommunicateToServer.hpp"

int	main(int, char **av)
{
	ParseArgs	*parse = new ParseArgs(av);
	clientSpace::CommunicateToServer	client(parse);

//	parse->Parser();
//	if (parse->checkArgs() == 84)
//		return (84);
	client.connectToServer();
	AI::ZappyAi AI(20, 20, client);
	AI.run(true);
	return 0;
}