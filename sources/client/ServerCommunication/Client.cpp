/*
** EPITECH PROJECT, 2018
** client
** File description:
** source
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "Client.hpp"

Client::Client()
{
}

Client::~Client()
{
}

struct protoent *Client::Proto()
{
	return getprotobyname("TCP");
}

int     Client::Socket()
{
	struct protoent	*pe = Proto();
	int		fd;

	if (!pe)
		return (84);
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1)
		return 84;
	return fd;
}

int	Client::connectFct(const char *ip, int port)
{
	struct sockaddr_in	s_in;
	int			fd = Socket();

	if (fd == 84)
		return (84);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = inet_addr(ip);
	if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		close(fd);
		return (84);
	}
	return fd;
}