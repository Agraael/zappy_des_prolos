//
// Created by Ludovica Pagliarani on 21/06/2018.
//

#include "GameMap.hpp"

graphic::GameMap::GameMap(graphic::IrrlichtLib *const lib) : _lib(lib)
{
}

void    graphic::GameMap::eventManager()
{
}

void    graphic::GameMap::display()
{
    Vector3d<int> max = {20, 20, 20};
    int id = 0;

    for (int y = -2; y < max.y + 2; y++) {
        for (int x = -2; x <max.x + 2; x++) {
                _lib->createCube({static_cast<double>(x), static_cast<double>(y), 0}, "../Assets/grass.png", id);
            id++;
        }
    }
    _lib->setCamera({(static_cast<double>(max.x) / 2), (static_cast<double>(max.y) / 2) - 15, static_cast<double>(max.z)},
    {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
}
