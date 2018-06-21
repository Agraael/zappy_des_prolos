/*
** EPITECH PROJECT, 2018
** client
** File description:
** header
*/

#ifndef COMMUNICATETOSERVER_HPP_
	#define COMMUNICATETOSERVER_HPP_

#include <memory>
#include "Client.hpp"
#include "ParseArgs.hpp"

namespace	serverSpace {

	enum	tilesType {
		NOTHING,
		LINEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHIRAS,
		THYSTAME
	};

	class CommunicateToServer {
		public:
			CommunicateToServer(ParseArgs *);
			~CommunicateToServer() {};
			int					connectToServer();
			bool					forward();
			bool					right();
			bool					left();
			std::vector<serverSpace::tilesType>	look();
			std::string				inventory();
			bool					broadcastText();
			int					connectNbr();
			bool					forkCmd();
			bool					eject();
			bool					takeObject();
			bool					setObject();
			bool					incantation();
		private:
			std::unique_ptr<Client>		_client;
			ParseArgs			*_parse;
			int				_fd;
	};
}

#endif /* !CONNECTTOSERVER_HPP_ */