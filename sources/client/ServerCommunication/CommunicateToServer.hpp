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
		FOOD,
		PLAYER
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
			std::pair<int, int>			teamName();			
		private:
			const std::unordered_map<std::string, clientSpace::tilesType>	_correlationTab = {
				{"", clientSpace::tilesType::NOTHING},
				{"limenate", clientSpace::tilesType::LINEMATE},
				{"deraumere", clientSpace::tilesType::DERAUMERE},
				{"sibur", clientSpace::tilesType::SIBUR},
				{"mendiane", clientSpace::tilesType::MENDIANE},
				{"phiras", clientSpace::tilesType::PHIRAS},
				{"thystane", clientSpace::tilesType::THYSTAME},
				{"food", clientSpace::tilesType::FOOD}
			};
			std::pair<int, int>			findMapSize(std::string str)
			int					checkNbrPlayer(std::string);
			const std::vector<std::string>		explode(const std::string& s, const char& c);
			std::vector<clientSpace::tilesType>	interpretTab(std::string);
			bool					interpretString(std::string str);
			std::unique_ptr<Client>		_client;
			ParseArgs			*_parse;
			int				_fd;
	};
}

#endif /* !CONNECTTOSERVER_HPP_ */