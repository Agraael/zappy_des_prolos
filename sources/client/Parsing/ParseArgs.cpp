/*
** EPITECH PROJECT, 2018
** server
** File description:
** source
*/

#include "ParseArgs.hpp"
#include "help.hpp"

ParseArgs::ParseArgs(char **av) : _name(""), _ip("127.0.0.1"), _port(0), _i(0)
{
	for (std::size_t i = 0; av[i] != nullptr; ++i)
		_av.push_back(av[i]);
	_av.push_back("");
}

void    ParseArgs::Parser()
{
	for (auto arg : _av) {
		for (auto param : _foncteur) {
			if (param.first == arg)
				param.second();
		}
		++_i;
	}
}

void	ParseArgs::help()
{
	std::cout << FIRSTLINE << std::endl;
	std::cout << SECONDLINE << std::endl;
	std::cout << THIRDLINE << std::endl;
	std::cout << FOURTHLINE << std::endl;
}

void	ParseArgs::setName()
{
	bool	exist = false;

	if (_av[_i + 1] == "")
		return;	
	else if (_name != "") {
		_name = "";
		return;
	}
	_name = _av[_i + 1];
	if (_av[_i + 2] == "")
		return;
	else {
		for (auto param : _foncteur) {
			if (param.first == _av[_i + 2])
				exist = true;
		}
	}
	if (exist == false)
		_name = "";
}

void	ParseArgs::setIp()
{
	bool	exist = false;

	if (_av[_i + 1] == "")
		return;
	_ip = _av[_i + 1];
	if (_av[_i + 2] == "")
		return;
	else {
		for (auto param : _foncteur) {
			if (param.first == _av[_i + 2])
				exist = true;
		}
	}
	if (exist == false)
		_ip = "";
}

void	ParseArgs::setPort()
{
	bool	exist = false;

	if (_av[_i + 1] == "")
		return;	
	_port = std::stoi (_av[_i + 1], nullptr, 10);
	if (_av[_i + 2] == "")
		return;
	else {
		for (auto param : _foncteur) {
			if (param.first == _av[_i + 2])
				exist = true;
		}
	}
	if (exist == false)
		_port = 0;
}

int	ParseArgs::checkArgs()
{
	if (_port == 0 || _name == "")
		return 84;
	return 0;
}