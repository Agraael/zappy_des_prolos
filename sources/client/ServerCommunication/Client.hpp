/*
** EPITECH PROJECT, 2018
** client
** File description:
** header
*/

#ifndef CLIENT_HPP_
	#define CLIENT_HPP_

#include <iostream>

class Client {
	public:
		Client();
		~Client();
		struct protoent	*Proto();
		int		Socket();
		int		connectFct(char const *, int);
		int		send(int fd, std::string);
		std::string	receive(int fd);
	private:
};

#endif /* !CLIENT_HPP_ */
