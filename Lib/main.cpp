//
// Created by Ludovica Pagliarani on 14/06/2018.
//

#include <chrono>
#include <thread>

#include "IrrlichtLib.hpp"
#include "GameInterface.hpp"

int main(int ac, char **av)
{
    graphic::IrrlichtLib *lib = new graphic::IrrlichtLib;
    lib->createBackground();
    std::string name = av[1];
    graphic::GameInterface gI(lib, name);
    gI.displayGameInterface();
    vec3df pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = -10;
    irr::u32 then = lib->getDevice()->getTimer()->getTime();
    auto element = lib->createSphere({10, 30, 0}, "../Assets/perso.png", 12);
    lib->setCamera(element, pos);
    while (lib->getDevice()->run()) {
       /* const irr::u32 now = lib->getDevice()->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;
        if(lib->getReceiver()->IsKeyDown(irr::KEY_LEFT)) {
            pos.y += 1.f;// * frameDeltaTime;
            //pos.x = 0.f;
        }
        else if(lib->getReceiver()->IsKeyDown(irr::KEY_RIGHT))
            pos.y -= 1.f;
        if(lib->getReceiver()->IsKeyDown(irr::KEY_DOWN))
            pos.y += 10.f;
        else if(lib->getReceiver()->IsKeyDown(irr::KEY_UP))
            pos.z -= 70.f * frameDeltaTime;
        lib->setCamera(element, pos);
        //lib->modifyPosElem(element, pos);*/
        lib->displayAll();
        gI.changeLevel(3);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

