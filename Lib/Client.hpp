//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#ifndef CLIENT_HPP
#define CLIENT_HPP

namespace Zappy
{
    class Client
    {
        std::string _name;
        size_t _lvl;
        std::unordered_map<std::string, size_t> _stones;
    public:
        Client();
        ~Client();
    };
}
#endif //CLIENT_HPP
