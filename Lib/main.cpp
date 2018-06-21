//
// Created by Ludovica Pagliarani on 14/06/2018.
//

#include <chrono>
#include <thread>

#include "IrrlichtLib.hpp"
#include "GameInterface.hpp"
#include "Inventary.hpp"
#include "GameMap.hpp"
#include "Player.hpp"

int main(int ac, char **av)
{
    graphic::IrrlichtLib *lib = new graphic::IrrlichtLib;
    std::string name = av[1];
    graphic::GameInterface gI(lib, name);
    graphic::GameMap map(lib);
    graphic::Player player(lib);
    /*graphic::Inventary inventary(lib);
    gI.display();
    vec3df pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = -10;
    irr::u32 then = lib->getDevice()->getTimer()->getTime();
    auto element = lib->createSphere({10, 30, 0}, "../Assets/perso.png", 12);
    lib->setCamera(element, pos);*/
    map.display();
    int i = 0;
    while (lib->getDevice()->run()) {
        if (i < 4) {
            player.eventManager("GO_LEFT");
        }
        lib->displayAll();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        i++;
        //gI.eventManager();
        //inventary.eventManager(gI.getInventaryIsOpen());
        //gI.changeLevel(3);
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

