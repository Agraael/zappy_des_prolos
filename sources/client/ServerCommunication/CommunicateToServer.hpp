/*
** EPITECH PROJECT, 2018
** client
** File description:
** header
*/

#ifndef COMMUNICATETOSERVER_HPP_
	#define COMMUNICATETOSERVER_HPP_

#include <memory>
#include <unordered_map>
#include "Client.hpp"
#include "ParseArgs.hpp"

namespace	clientSpace {

	enum	tilesType {
		NOTHING,
		LINEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHIRAS,
		THYSTAME,
		FOOD
	};

	class CommunicateToServer {
		public:
			CommunicateToServer(ParseArgs *);
			~CommunicateToServer() {};
			int					connectToServer();
			bool					forward();
			bool					right();
			bool					left();
			std::vector<clientSpace::tilesType>	look();
			std::vector<clientSpace::tilesType>	inventory();
			bool					broadcastText();
			int					connectNbr();
			bool					forkCmd();
			bool					eject();
			bool					takeObject();
			bool					setObject();
			bool					incantation();
		private:
			const static std::unordered_map<char, serverSpace::tilesType>	_correlationTab = {
				{"", clientSpace::tilesType::NOTHING},
				{"", clientSpace::tilesType::LINEMATE},
				{"", clientSpace::tilesType::DERAUMERE},
				{"", clientSpace::tilesType::SIBUR},
				{"", clientSpace::tilesType::MENDIANE},
				{"", clientSpace::tilesType::PHIRAS},
				{"", clientSpace::tilesType::THYSTAME},
				{"", clientSpace::tilesType::FOOD}
			}
			std::vector<serverSpace::tilesType>	interpretTab(std::string);
			std::unique_ptr<Client>		_client;
			ParseArgs			*_parse;
			int				_fd;
	};
}

#endif /* !CONNECTTOSERVER_HPP_ */