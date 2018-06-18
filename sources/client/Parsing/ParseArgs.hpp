/*
** EPITECH PROJECT, 2018
** client
** File description:
** header
*/

#ifndef PARSEARGS_HPP_
	#define PARSEARGS_HPP_

#include <functional>
#include <vector>
#include <iostream>
#include <unordered_map>

class ParseArgs {
	public:
		ParseArgs(char **);
		void    	Parser();
		void		help();
		std::string	getName() const noexcept { return _name; };
		std::string	getIp() const noexcept { return _ip; };
		int		getPort() const noexcept { return _port; };
		int		checkArgs();
	private:
		void	setName();
		void	setIp();
		void	setPort();

		std::string			_name;
		std::string			_ip;
		int				_port;
		std::size_t			_i;
		std::vector<std::string>	_av;
		using	partsParametres = std::function<void()>;
		using	ptrMapFunc = std::unordered_map<std::string, partsParametres>;
		ptrMapFunc _foncteur {
			{"-help", [this]() { return this->help(); }},
			{"-p", [this]() { return this->setPort(); }},
			{"-n", [this]() { return this->setName(); }},
			{"-h", [this]() { return this->setIp(); }}
		};
};

#endif /* !PARSEARGS_HPP_ */
