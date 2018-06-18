/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include "ConnectToServer.hpp"

ConnectToServer::ConnectToServer(ParseArgs parse) : _parse(parse)
{
}

void	ConnectToServer::connectServer()
{
	Client	client;
	int	_port;

	_port = client.connectFct(_parse.getIp().c_str(), _parse.getPort());
}