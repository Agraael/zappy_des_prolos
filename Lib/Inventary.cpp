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

void    graphic::Inventary::eventManager(bool isOpen)
{
    if (isOpen)
        createWindowInventary();
    //if (_lib->getEventManager()->IsButtonClicked(graphic::controllerUser::OPEN_INVENTARY) == true)
        //std::cout << "open" << std::endl;
    if (_lib->getEventManager()->IsButtonClicked(graphic::controllerUser::CLOSE_INVENTARY) == true)
        std::cout << "open" << std::endl;
}

void    graphic::Inventary::createWindowInventary()
{
    //IGUIWindow* window = env->addWindow(
            //rect<s32>(100 + Context.counter, 100 + Context.counter, 300 + Context.counter, 200 + Context.counter), false, L"Test window");
}

