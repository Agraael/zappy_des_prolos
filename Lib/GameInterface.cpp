//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#include "GameInterface.hpp"

graphic::GameInterface::GameInterface(graphic::IrrlichtLib *const lib, std::string const& nameTeam) : _lib(lib), _teamName(nameTeam)
{
}

void graphic::GameInterface::printName()
{
    std::vector<std::string> lettersTeam = _teamName.getVectorLetters();
    infos_t letterInfos;
    size_t i = 100;
    letterInfos._y = 600;
    letterInfos._w = 20;
    letterInfos._h = 20;
    letterInfos._maxH = 20;
    letterInfos._maxW = 20;
    for (auto &letter : lettersTeam) {
        letterInfos._path = letter;
        letterInfos._x = i;
        _lib->drawImage(letterInfos);
        i += 15;
    }
}

void    graphic::GameInterface::buttonInventary()
{
    auto size = _lib->getScreenSize();
    graphic::infos_t menuStone;
    menuStone._x = (size.x / 2) - 50;
    menuStone._y = 10;
    menuStone._w = (size.x / 2) + 50;
    menuStone._h = 100;
    menuStone._type = graphic::OPEN_INVENTARY;
    menuStone._desc = "get a look to your inventary";
    menuStone._name = "";
    menuStone._path = "./../Assets/menuStones.png";
    _lib->printButton(menuStone);
}


void graphic::GameInterface::printBackTeam()
{
    int size = 330 + ((_teamName.getVectorLetters()).size() * 25);
    infos_t backTeam;
    backTeam._x = 80;
    backTeam._y = 540;
    backTeam._w = size;
    backTeam._h = 150;
    backTeam._path = "./../Assets/barr_informations.png";
    backTeam._maxW = size;
    backTeam._maxH = 150;
    _lib->drawImage(backTeam);
}

void graphic::GameInterface::displayGameInterface()
{
    buttonInventary();
    printBackTeam();
    printName();
    printLevel(8);
    printLife(10);
}

std::string graphic::GameInterface::changeInformationsPath(size_t nbr, const std::string &path)
{
    std::string str;
    sprintf(const_cast<char *>(str.c_str()), "%d", nbr);
    std::string finalPath(path);
    finalPath += str.c_str();
    finalPath += ".png";
    return finalPath;
}

void    graphic::GameInterface::printLevel(size_t lvl)
{
    int size = ((_teamName.getVectorLetters()).size() * 25) + 39;
    _lvl._infos._x = size;
    _lvl._infos._y = 619;
    _lvl._infos._w = 43.5 * lvl;
    _lvl._infos._h = 23;
    _lvl._infos._maxW = 43.5 * lvl;
    _lvl._infos._maxH = 23;
    _lvl._infos._path = changeInformationsPath(lvl, "../Assets/lvl_");
    _lvl._img = _lib->drawImage(_lvl._infos);
}

void    graphic::GameInterface::printLife(size_t life)
{
    int size = ((_teamName.getVectorLetters()).size() * 25) + 39.5;
    _life._infos._x = size;
    _life._infos._y = 583;
    _life._infos._w = 34.5 * life;
    _life._infos._h = 23;
    _life._infos._maxW = 34.5 * life;
    _life._infos._maxH = 23;
    std::string strLvl;
    _life._infos._path = changeInformationsPath(life, "../Assets/life_");
    _life._img = _lib->drawImage(_life._infos);
}

void    graphic::GameInterface::changeLife(size_t life)
{
    _life._img->remove();
    _life._infos._w = 34.5 * life;
    _life._infos._maxW = 34.5 * life;
    _life._infos._path = changeInformationsPath(life, "../Assets/life_");
    _life._img = _lib->drawImage(_life._infos);
}

void    graphic::GameInterface::changeLevel(size_t lvl)
{
    _lvl._img->remove();
    _lvl._infos._w = 43.5 * lvl;
    _lvl._infos._maxW = 43.5 * lvl;
    _lvl._infos._path = changeInformationsPath(lvl, "../Assets/lvl_");
    _lvl._img = _lib->drawImage(_lvl._infos);
}

/*
printStoneButton();
displayClientInterface();*/


