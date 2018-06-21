/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <iostream>
#include "CommunicateToServer.hpp"

serverSpace::CommunicateToServer::CommunicateToServer(ParseArgs *parse) : _parse(parse)
{
	_client = std::make_unique<Client>();
}

int	serverSpace::CommunicateToServer::connectToServer()
{
	_fd = _client->connectFct(_parse->getIp().c_str(), _parse->getPort());

	if (_fd == 84)
		return 84;
	_client->send(_fd, "team-name " + _parse->getName());
	_client->receive(_fd);
	forward();
	right();	
	return 0;
}

bool	serverSpace::CommunicateToServer::forward()
{
	_client->send(_fd, "forward");
	_client->receive(_fd);
	return true;
}

bool	serverSpace::CommunicateToServer::right()
{
	_client->send(_fd, "right");
	_client->receive(_fd);
	return false;
}

bool	serverSpace::CommunicateToServer::left()
{
	_client->send(_fd, "left");
	_client->receive(_fd);
	return true;
}

std::vector<serverSpace::tilesType>	serverSpace::CommunicateToServer::look()
{
	_client->send(_fd, "look");
	_client->receive(_fd);
	return {};
}

std::string	serverSpace::CommunicateToServer::inventory()
{
	_client->send(_fd, "inventory");
	_client->receive(_fd);
	return "";
}

bool	serverSpace::CommunicateToServer::broadcastText()
{
	_client->send(_fd, "Broadcast text");
	_client->receive(_fd);
	return true;
}

int	serverSpace::CommunicateToServer::connectNbr()
{
	_client->send(_fd, "Connect_nbr");
	_client->receive(_fd);
	return 1;
}

bool	serverSpace::CommunicateToServer::forkCmd()
{
	_client->send(_fd, "Fork");
	_client->receive(_fd);
	return true;
}

bool	serverSpace::CommunicateToServer::eject()
{
	_client->send(_fd, "Eject");
	_client->receive(_fd);
	return false;
}

bool	serverSpace::CommunicateToServer::takeObject()
{
	_client->send(_fd, "Take object");
	_client->receive(_fd);
	return true;
}

bool	serverSpace::CommunicateToServer::setObject()
{
	_client->send(_fd, "Set object");
	_client->receive(_fd);
	return false;
}

bool	serverSpace::CommunicateToServer::incantation()
{
	_client->send(_fd, "Incantation");
	_client->receive(_fd);
	return true;
}