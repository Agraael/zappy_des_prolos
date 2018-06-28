//
// Created by Ludovica Pagliarani on 20/06/2018.
//

#include "Inventary.hpp"

graphic::Inventary::Inventary(graphic::IrrlichtLib *const lib) : _lib(lib)
{
    _size = _lib->getScreenSize();
}

void    graphic::Inventary::display()
{
    printBackground();
    printLinemate(3);
    printDeraumere(5);
    printSibur(1);
    printMendiane(7);
    printPhiras(9);
    printThystame(2);


}

void    graphic::Inventary::printBackground()
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 80;
    backTeam._w = 400;
    backTeam._h = 300;
    backTeam._path = "./../Assets/back_inventary.jpg";
    backTeam._maxW = 400;
    backTeam._maxH = 300;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::printLinemate(size_t nbrStone)
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 100;
    backTeam._w = 50;
    backTeam._h = 50;
    backTeam._path = "./../Assets/linemate.png";
    backTeam._maxW = 50;
    backTeam._maxH = 50;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::printDeraumere(size_t nbrStone)
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 160;
    backTeam._w = 50;
    backTeam._h = 50;
    backTeam._path = "./../Assets/deraumere.png";
    backTeam._maxW = 50;
    backTeam._maxH = 50;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::printSibur(size_t nbrStone)
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 210;
    backTeam._w = 50;
    backTeam._h = 50;
    backTeam._path = "./../Assets/sibur.png";
    backTeam._maxW = 50;
    backTeam._maxH = 50;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::printMendiane(size_t nbrStone)
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 260;
    backTeam._w = 50;
    backTeam._h = 50;
    backTeam._path = "./../Assets/mendiane.png";
    backTeam._maxW = 50;
    backTeam._maxH = 50;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::printPhiras(size_t nbrStone)
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 310;
    backTeam._w = 50;
    backTeam._h = 50;
    backTeam._path = "./../Assets/phiras.png";
    backTeam._maxW = 50;
    backTeam._maxH = 50;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::printThystame(size_t nbrStone)
{
    infos_t backTeam;
    backTeam._x = _size.x / 2 - 200;
    backTeam._y = 360;
    backTeam._w = 50;
    backTeam._h = 50;
    backTeam._path = "./../Assets/thystame.png";
    backTeam._maxW = 50;
    backTeam._maxH = 50;
    _lib->drawImage(backTeam);
}

void    graphic::Inventary::eventManager(bool isOpen)
{
    _isOpen = isOpen;
    if (_isOpen)
        createWindowInventary();
}

void    graphic::Inventary::createWindowInventary()
{
    auto size = _lib->getScreenSize();

    //auto env = _lib->createNewWindow(size.x / 2 - 100, 50, 2000, 500);
    /*graphic::infos_t menuStone;
    menuStone._x = 50;
    menuStone._y = 10;
    menuStone._w = 100;
    menuStone._h = 30;
    menuStone._type = graphic::SHOW_LINEMATE;
    menuStone._desc = "get a look to deraumere";
    menuStone._name = "";
    menuStone._path = "./../Assets/linemate.jpeg";
    _lib->printButton(menuStone, env);*/
}

