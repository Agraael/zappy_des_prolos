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
			int							connectToServer();
			bool							forward();
			bool							right();
			bool							left();
			std::vector<std::vector<clientSpace::tilesType>>	look();
			std::vector<std::pair<clientSpace::tilesType, int>>	inventory();
			bool							broadcastText();
			int							connectNbr();
			bool							forkCmd();
			bool							eject();
			bool							takeObject();
			bool							setObject();
			bool							incantation();
			int							teamName();
			std::pair<int, int>					getSize() { return _mapSize; };
		private:
			const std::unordered_map<std::string, clientSpace::tilesType>	_correlationTab = {
				{"", clientSpace::tilesType::NOTHING},
				{"linemate", clientSpace::tilesType::LINEMATE},
				{"deraumere", clientSpace::tilesType::DERAUMERE},
				{"sibur", clientSpace::tilesType::SIBUR},
				{"mendiane", clientSpace::tilesType::MENDIANE},
				{"phiras", clientSpace::tilesType::PHIRAS},
				{"thystame", clientSpace::tilesType::THYSTAME},
				{"food", clientSpace::tilesType::FOOD},
				{"player", clientSpace::tilesType::PLAYER}
			};
			std::unique_ptr<Client>						_client;
			ParseArgs							*_parse;
			int								_fd;
			std::pair<int, int>						_mapSize;
			std::vector<std::pair<clientSpace::tilesType, int>>		_vec;

			std::vector<clientSpace::tilesType>			convertTab(std::vector<std::string>);
			void							findMapSize(std::string str);
			int							checkNbrPlayer(std::string);
			const std::vector<std::string>				explode(const std::string& s, const char& c);
			std::vector<std::vector<clientSpace::tilesType>>	interpretTabLook(std::string);
			void							interpretTabInventory(std::string);
			bool							interpretString(std::string str);
	};
}

#endif /* !CONNECTTOSERVER_HPP_ */