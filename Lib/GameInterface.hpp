//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#ifndef GAMEINTERFACE_HPP
#define GAMEINTERFACE_HPP

#include "IGrphGame.hpp"
#include "IrrlichtLib.hpp"
#include "LettersController.hpp"
//#include "Inventary.hpp"

namespace graphic {
    typedef struct infosPlayer_s {
        infos_t _infos;
        irr::gui::IGUIImage *_img;
    } infosPlayer_t;

    class GameInterface : public IGrphGame
    {
        graphic::IrrlichtLib *_lib;
        graphic::LetterController _teamName;
        infosPlayer_t _lvl;
        infosPlayer_t _life;
        bool _inventaryIsOpen;
    public:
        GameInterface(graphic::IrrlichtLib *const irrlichtLib, std::string const &nameTeam);
        ~GameInterface() = default;
        void display(); //function de l'interface
        void eventManager(); //function de l'interface
        void printName();
        void printBackTeam();
        bool getInventaryIsOpen() { return _inventaryIsOpen; }
        void buttonInventary();
        std::string changeInformationsPath(size_t nbr, const std::string &path);
        void changeLevel(size_t);
        void changeLife(size_t);
        void printGrass();
        void infoBarPlayer();
        void printLevel(size_t);
        void printLife(size_t);
        void printStoneButton();
        void displayClientInterface();
    };
}

#endif //GAMEINTERFACE_HPP
