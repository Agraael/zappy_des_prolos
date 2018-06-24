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
	_vec.push_back(std::make_pair(clientSpace::tilesType::LINEMATE, 0));
	_vec.push_back(std::make_pair(clientSpace::tilesType::DERAUMERE, 0));
	_vec.push_back(std::make_pair(clientSpace::tilesType::SIBUR, 0));
	_vec.push_back(std::make_pair(clientSpace::tilesType::MENDIANE, 0));
	_vec.push_back(std::make_pair(clientSpace::tilesType::PHIRAS, 0));
	_vec.push_back(std::make_pair(clientSpace::tilesType::THYSTAME, 0));	
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
	if (teamName() == 84)
		return 84;
	incantation();
	return 0;
}

int	clientSpace::CommunicateToServer::checkNbrPlayer(std::string str)
{
	std::size_t	pos = str.find(" ");

	if (str == "ko")
		return (-1);
	str.erase(str.begin() + pos, str.end());
	if (str == "team" || str == "ko")
		return (-1);
	return std::stoi(str);
}

int	clientSpace::CommunicateToServer::teamName()
{
	std::string	buffer = "";

	_client->send(_fd, "team-name " + _parse->getName());
	while ((buffer = _client->receive(_fd)) == "");
	if (checkNbrPlayer(buffer) < 0)
		return 84;
	while ((buffer = _client->receive(_fd)) == "");
	findMapSize(buffer);
	return (0);
}

void	clientSpace::CommunicateToServer::findMapSize(std::string str)
{
	int		x = 0;
	int		y = 0;
	std::string	temp = str;
	std::size_t	pos1 = str.find(" ");
	std::size_t	pos2;

	temp.erase(temp.begin() + pos1, temp.end());
	x =  std::stoi(temp);
	str = &str[pos1];
	pos2 = str.find(" ");
	str.erase(str.begin() + pos1 + pos2 + 1, str.end());
	y =  std::stoi(str);
	_mapSize = std::make_pair(x, y);
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
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::left()
{
	std::string	buffer = "";

	_client->send(_fd, "left");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

std::vector<std::vector<clientSpace::tilesType>>	clientSpace::CommunicateToServer::look()
{
	std::string	buffer = "";

	_client->send(_fd, "look");
	while ((buffer += _client->receive(_fd)) == "");
	return {interpretTabLook(buffer)};
}

std::vector<std::pair<clientSpace::tilesType, int>>	clientSpace::CommunicateToServer::inventory()
{
	std::string	buffer = "";

	_client->send(_fd, "inventory");
	while ((buffer += _client->receive(_fd)) == "");
	interpretTabInventory(buffer);
	return _vec;
}

bool	clientSpace::CommunicateToServer::broadcastText()
{
	std::string	buffer = "";

	_client->send(_fd, "broadcast text");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

int	clientSpace::CommunicateToServer::connectNbr()
{
	std::string	buffer = "";
	std::size_t	pos;

	_client->send(_fd, "connect_nbr");
	while ((buffer += _client->receive(_fd)) == "");
	pos = buffer.find(" ");
	buffer.erase(buffer.begin(), buffer.begin() + pos + 1);
	return std::stoi(buffer);
}

bool	clientSpace::CommunicateToServer::forkCmd()
{
	std::string	buffer = "";

	_client->send(_fd, "Fork");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::eject()
{
	std::string	buffer = "";

	_client->send(_fd, "Eject");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::takeObject()
{
	std::string	buffer = "";

	_client->send(_fd, "take object");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::setObject()
{
	std::string	buffer = "";

	_client->send(_fd, "set object");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

bool	clientSpace::CommunicateToServer::incantation()
{
	std::string	buffer = "";

	_client->send(_fd, "incantation");
	while ((buffer += _client->receive(_fd)) == "");
	return interpretString(buffer);
}

const std::vector<std::string> clientSpace::CommunicateToServer::explode(const std::string& s, const char& c)
{
	std::string buff{""};
	std::vector<std::string> v;
	
	for(auto n:s) {
		if (n != c)
			buff+=n;
		else {
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "") {
		v.push_back(buff);
	}
	
	return v;
}

std::vector<clientSpace::tilesType>	clientSpace::CommunicateToServer::convertTab(std::vector<std::string> tab)
{
	std::vector<clientSpace::tilesType>	tilesTab;

	for (auto elem : tab) {
		for (auto tile : _correlationTab) {
			if (elem == tile.first)
				tilesTab.push_back(tile.second);
		}
	}
	return tilesTab;
}

void	clientSpace::CommunicateToServer::interpretTabInventory(std::string tab)
{
	tab.erase(std::remove(tab.begin(), tab.end(), '['), tab.end());
	tab.erase(std::remove(tab.begin(), tab.end(), ']'), tab.end());
	std::vector<std::string>	v{explode(tab, ',')};
	std::vector<int>		intsTab;
	std::size_t			pos;
	std::size_t			i = 0;

	for (auto n : v) {
		pos = n.find(" ");
		n.erase(n.begin(), n.begin() + pos + 1);
		_vec[i].second = std::atoi(n.c_str());
		++i;
	}
}

std::vector<std::vector<clientSpace::tilesType>>	clientSpace::CommunicateToServer::interpretTabLook(std::string tab)
{
	tab.erase(std::remove(tab.begin(), tab.end(), '['), tab.end());
	tab.erase(std::remove(tab.begin(), tab.end(), ']'), tab.end());	
	std::vector<std::string>				v{explode(tab, ',')};
	std::vector<std::vector<clientSpace::tilesType>>	tilesTab;

	for (auto n:v) {
		std::vector<std::string>	tilesVec{explode(n, ' ')};
		if (n == "")
			tilesVec = {""};
		tilesTab.push_back(convertTab(tilesVec));
	}
	return tilesTab;
}

bool	clientSpace::CommunicateToServer::interpretString(std::string str)
{
	if (str.find("ok") < str.size())
		return (true);
	else if (str.find("ko") < str.size())
		return (false);
	return (false);
}