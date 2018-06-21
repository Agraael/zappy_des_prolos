//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#include "Player.hpp"

graphic::Player::Player(graphic::IrrlichtLib *const lib) : _lib(lib)
{
    infos_t playerButton;
    playerButton._x = 10;
    playerButton._y = 15;
    playerButton._w = 20;
    playerButton._h = 30;
    playerButton._type = graphic::OPEN_INVENTARY;
    playerButton._desc = "get a look to your player informations";
    playerButton._name = "";
    playerButton._path = "./../Assets/player_infos.png";
    _lib->printButton(playerButton);
    _pos = {10, 15, 0};
    _player = _lib->createPlayer({(double)_pos.x, (double)_pos.y, 0}, "../Assets/perso.png", 1234);
}

void    graphic::Player::eventManager(const std::string &cmd)
{
    for (std::unordered_map<std::string, std::function<void()>>::iterator it= _commands.begin(); it!=_commands.end(); ++it) {
        if (it->first == cmd) {
            it->second();
        }
    }
}
