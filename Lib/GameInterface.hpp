//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#ifndef GAMEINTERFACE_HPP
#define GAMEINTERFACE_HPP

#include "IrrlichtLib.hpp"
#include "LettersController.hpp"

namespace graphic
{
    typedef struct infosPlayer_s
    {
       infos_t _infos;
       irr::gui::IGUIImage	*_img;
    } infosPlayer_t;

    class GameInterface
    {
        graphic::IrrlichtLib *_lib;
        graphic::LetterController _teamName;
        infosPlayer_t _lvl;
        infosPlayer_t _life;
    public:
        GameInterface(graphic::IrrlichtLib *const irrlichtLib, std::string const& nameTeam);
        ~GameInterface() = default;
        void printName();
        void printBackTeam();
        std::string changeInformationsPath(size_t nbr, const std::string &path);
        void changeLevel(size_t);
        void changeLife(size_t);
        void displayGameInterface();
        void infoBarPlayer();
        void printLevel(size_t);
        void printLife(size_t);
        void printStoneButton();
        void displayClientInterface();
    };
}

#endif //GAMEINTERFACE_HPP
