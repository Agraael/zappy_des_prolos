//
// Created by Ludovica Pagliarani on 21/06/2018.
//

#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include "IrrlichtLib.hpp"
#include "IGrphGame.hpp"
#include <vector>

namespace graphic
{
    class GameMap : public IGrphGame
    {
        graphic::IrrlichtLib *_lib;
        size_t _width;
        size_t _height;
    public:
        GameMap(graphic::IrrlichtLib *const lib , size_t width, size_t height);
        ~GameMap() = default;
        void display();
        void eventManager();

    };
}
#endif //GAMEMAP_HPP
