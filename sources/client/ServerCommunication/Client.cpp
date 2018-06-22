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
#include <string.h>
#include "Client.hpp"

#include <string>
#include <fcntl.h>
#include <sys/types.h>
#include <iostream>

#include <ext/stdio_filebuf.h>
#include <fstream>

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

int	Client::send(int fd, std::string msg)
{
	dprintf(fd, "%s\n", msg.c_str());
	/*nbWrited = write(fd, msg.c_str(), msg.size());
	if (nbWrited < 0) {
		std::cerr << "Error : can't send from client to server" << std::endl;
		close(fd);
		return (84);
		}*/
	return (0);
}

std::string	Client::receive(int fd)
{
	char *buff = (char *)malloc(sizeof(char) * 512);
        int pos_end = read(fd, buff, 1);

        if (pos_end > 0) {
                while (1) {
                        if (pos_end > 0)
                                printf("%c", buff[0]);
                        pos_end = read(fd, buff, 1);
                        if (buff[0] == '\n')
                                break;
                }
                printf("\n");
        } else
		return "";
	std::string buffer(buff);
	free(buff);
	return buffer;
}

// Completer cette ligne dans add_client : e->fct_write[cs] = client_write;

void client_write(int fd, char *msg)
{
	send(fd, msg, strlen(msg), 0);
}
