/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include <algorithm>
#include <iostream>
#include <fcntl.h>
#include "CommunicateToServer.hpp"

clientSpace::CommunicateToServer::CommunicateToServer(ParseArgs *parse) : _parse(parse)
{
	_client = std::make_unique<Client>();
}

int	clientSpace::CommunicateToServer::connectToServer()
{
	int flag;

	_fd = _client->connectFct(_parse->getIp().c_str(), _parse->getPort());

	if (_fd == 84)
		return 84;
	flag = fcntl(_fd, F_GETFL, 0);
	flag |= O_NONBLOCK;
        fcntl(_fd, F_SETFL, flag);
	if (teamName() == std::make_pair(0, 0))
		return 84;
	return 0;
}

int	clientSpace::CommunicateToServer::checkNbrPlayer(std::string str)
{
	std::size_t	pos = str.find(" ");

	str.erase(str.begin() + pos, str.end());
	return std::stoi(str);
}

std::pair<int, int>	clientSpace::CommunicateToServer::teamName()
{
	std::string	buffer = "";

	_client->send(_fd, "team-name " + _parse->getName());
	while ((buffer = _client->receive(_fd)) == "");
	if (checkNbrPlayer(buffer) < 0)
		return std::make_pair(0, 0);
	while ((buffer = _client->receive(_fd)) == "");
	return (findMapSize(buffer));
}

std::pair<int, int>	clientSpace::CommunicateToServer::findMapSize(std::string str)
{
	int	x = 0;
	int	y = 0;
	std::string	temp = 
	std::size_t	pos1 = str.find(" ");


	std::size_t	pos2 = str.find(" ");

}

bool	clientSpace::CommunicateToServer::forward()
{
	std::string	buffer = "";

	_client->send(_fd, "forward");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::right()
{
	std::string	buffer = "";

	_client->send(_fd, "right");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::left()
{
	std::string	buffer = "";

	_client->send(_fd, "left");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

std::vector<clientSpace::tilesType>	clientSpace::CommunicateToServer::look()
{
	std::string	buffer = "";

	_client->send(_fd, "look");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretTab(buffer);
}

std::vector<clientSpace::tilesType>	clientSpace::CommunicateToServer::inventory()
{
	std::string	buffer = "";

	_client->send(_fd, "inventory");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretTab(buffer);
}

bool	clientSpace::CommunicateToServer::broadcastText()
{
	std::string	buffer = "";

	_client->send(_fd, "Broadcast text");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

int	clientSpace::CommunicateToServer::connectNbr()
{
	_client->send(_fd, "Connect_nbr");
	_client->receive(_fd);
	return 1;
}

bool	clientSpace::CommunicateToServer::forkCmd()
{
	std::string	buffer = "";

	_client->send(_fd, "Fork");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::eject()
{
	std::string	buffer = "";

	_client->send(_fd, "Eject");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::takeObject()
{
	std::string	buffer = "";

	_client->send(_fd, "Take object");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::setObject()
{
	std::string	buffer = "";

	_client->send(_fd, "Set object");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::incantation()
{
	std::string	buffer = "";

	_client->send(_fd, "Incantation");
	while ((buffer += _client->receive(_fd)) == "");
	std::cout << buffer << std::endl;
	return interpretString(buffer);
}

const std::vector<std::string> clientSpace::CommunicateToServer::explode(const std::string& s, const char& c)
{
	std::string buff{""};
	std::vector<std::string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if (buff != "") v.push_back(buff);
	
	return v;
}

std::vector<clientSpace::tilesType>	clientSpace::CommunicateToServer::interpretTab(std::string tab)
{
	std::vector<std::string> 		vec{explode(tab, ',')};
	std::vector<clientSpace::tilesType>	tilesTab;

	for (auto &n : vec)
		n.erase(std::remove(n.begin(), n.end(), ' '), n.end());
	for (auto &n : vec) {
		for (auto elem : _correlationTab) {
			if (n == elem.first)
				tilesTab.push_back(elem.second);
		}
	}
}

bool	clientSpace::CommunicateToServer::interpretString(std::string str)
{
	if (str.find("ok") < str.size())
		return (true);
	else if (str.find("ko") < str.size())
		return (true);
}