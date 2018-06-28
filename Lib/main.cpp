//
// Created by Ludovica Pagliarani on 14/06/2018.
//

#include <chrono>
#include <thread>

#include "IrrlichtLib.hpp"
#include "IGrphGame.hpp"
#include "GameInterface.hpp"
#include "Inventary.hpp"
#include "GameMap.hpp"
#include "Player.hpp"

int main(int ac, char **av)
{
    graphic::IrrlichtLib *lib = new graphic::IrrlichtLib;
    graphic::Vector3d<int> size = {20, 20, 20};
    std::string name = av[1];
    graphic::GameInterface gI(lib, name);
    graphic::GameMap map(lib, 20, 20);
    graphic::Player player(lib);
    gI.display();
    map.display();
    int i = 0;
    while (lib->getDevice()->run()) {
        if (i < 4) {
            player.eventManager("GO_LEFT");
        }
        lib->displayAll();
        i++;
        gI.eventManager();
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

