/*
** EPITECH PROJECT, 2018
** client
** File description:
** header
*/

#ifndef CLIENT_HPP_
	#define CLIENT_HPP_

class Client {
	public:
		Client();
		~Client();
		struct protoent	*Proto();
		int		Socket();
		int		connectFct(char const *, int);		
	private:
};

#endif /* !CLIENT_HPP_ */
