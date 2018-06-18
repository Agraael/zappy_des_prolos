/*
** EPITECH PROJECT, 2018
** client
** File description:
** header
*/

#ifndef CONNECTTOSERVER_HPP_
	#define CONNECTTOSERVER_HPP_

#include "Client.hpp"
#include "ParseArgs.hpp"

class ConnectToServer {
	public:
		ConnectToServer(ParseArgs);
		~ConnectToServer() {};
		void	connectServer();
	private:
		ParseArgs	_parse;
};

#endif /* !CONNECTTOSERVER_HPP_ */