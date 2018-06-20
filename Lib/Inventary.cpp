//
// Created by Ludovica Pagliarani on 20/06/2018.
//

#include "Inventary.hpp"

graphic::Inventary::Inventary(graphic::IrrlichtLib *const lib) : _lib(lib)
{
}

void    graphic::Inventary::display()
{
    eventManager();
}

void    graphic::Inventary::printLinemate(size_t nbrStone)
{
}

void    graphic::Inventary::printDeraumere(size_t nbrStone)
{
}
void    graphic::Inventary::printSibur(size_t nbrStone)
{
}

void    graphic::Inventary::printMendiane(size_t nbrStone)
{
}

void    graphic::Inventary::printPhiras(size_t nbrStone)
{
}

void    graphic::Inventary::printThystame(size_t nbrStone)
{
}

void    graphic::Inventary::eventManager()
{
    if (_lib->getEventManager()->IsButtonClicked(graphic::controllerUser::OPEN_INVENTARY) == true)
        std::cout << "open" << std::endl;//game.saveGame();
    if (_lib->getEventManager()->IsButtonClicked(graphic::controllerUser::CLOSE_INVENTARY) == true)
        std::cout << "open" << std::endl;
}

/*void    graphic::Inventary::printContinue()
{
    graphic::infos_t btn;
    vec2d size = _lib->getScreenSize();
    btn._x = (size.x / 2) - 100;
    btn._y = 200;
    btn._w = (size.x / 2) + 100;
    btn._h = 250;
    btn._type = graphic::controllerUser::CONTINUE;
    btn._desc = "Continue";
    btn._name = "Continue";
    btn._path = "Assets/media/button_menu.png";
    _lib->printButton(btn);
}

void    graphic::Inventary::printSave()
{
    graphic::infos_t btn;
    vec2d size = _lib->getScreenSize();
    btn._x = (size.x / 2) - 100;
    btn._y = 300;
    btn._w = (size.x / 2) + 100;
    btn._h = 350;
    btn._type = graphic::controllerUser::SAVE;
    btn._desc = "Save";
    btn._name = "Save";
    btn._path = "Assets/media/button_menu.png";
    _lib->printButton(btn);
}

void    graphic::Inventary::printQuit()
{
    graphic::infos_t btn;
    vec2d size = _lib->getScreenSize();
    btn._x = (size.x / 2) - 100;
    btn._y = 400;
    btn._w = (size.x / 2) + 100;
    btn._h = 450;
    btn._type = graphic::controllerUser::MENU;
    btn._desc = "Quit";
    btn._name = "Quit";
    btn._path = "Assets/media/button_menu.png";
    _lib->printButton(btn);
}*/

