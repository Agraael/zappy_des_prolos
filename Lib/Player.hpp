//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iterator>
#include <iostream>
#include <functional>
#include <unordered_map>
#include "IGrphGame.hpp"
#include "IrrlichtLib.hpp"

namespace graphic
{
    class Player
    {
        graphic::IrrlichtLib *_lib;
        irr::scene::ISceneNode *_player;
        Vector3d<int> _pos;
        std::unordered_map<std::string, std::function<void()>> _commands = {
            {"GO_LEFT", [this]() { _pos.x += 1; std::cout << "looool" << std::endl; updatePosPlayer(); }},
            {"GO_RIGHT", [this]() { _pos.x -= 1; updatePosPlayer(); }},
            {"GO_UP", [this]() { _pos.y += 1; updatePosPlayer(); }},
            {"GO_DOWN", [this]() { _pos.y -= 1; updatePosPlayer(); }},
        };
    public:
        Player(graphic::IrrlichtLib *const lib);
        ~Player() = default;
        void eventManager(const std::string &cmd);
        void updatePosPlayer() { _player->setPosition(irr::core::vector3df({static_cast<float>(_pos.x), static_cast<float>(_pos.y), 0})); }
    };
}
#endif //CLIENT_HPP
