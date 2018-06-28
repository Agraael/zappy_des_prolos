//
// Created by Ludovica Pagliarani on 21/06/2018.
//

#include "GameMap.hpp"

graphic::GameMap::GameMap(graphic::IrrlichtLib *const lib, size_t w, size_t h) : _lib(lib) , _width(w), _height(h)
{
}

void    graphic::GameMap::eventManager()
{
}

void    graphic::GameMap::display()
{
    int id = 0;

    for (int y = 0; y < _height + 2; y++) {
        for (int x = 0; x < _width + 2; x++) {
                _lib->createCube({static_cast<double>(x), static_cast<double>(y), 0}, "../Assets/grass.png", id);
            id++;
        }
    }
    int z = _height;
    if (_height < _width)
        z = _width;
    _lib->setCamera({(static_cast<double>(_width) / 2), (static_cast<double>(_height) / 2) - 15, static_cast<double>(z)},
    {static_cast<double>(_width) / 2, static_cast<double>(_height) / 2, 0});
}
