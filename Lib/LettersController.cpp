//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#include "LettersController.hpp"

graphic::LetterController::LetterController(const std::string &toPrint) : _toPrint(toPrint)
{
    std::transform(_toPrint.begin(), _toPrint.end(), _toPrint.begin(), ::toupper);
    createVectorToPrint();
    for (auto let : _textureToPrint) {
        std::cout << "              " << let << std::endl;
    }
};

void graphic::LetterController::createVectorToPrint()
{
    for (auto &character : _toPrint) {
        std::unordered_map<char, std::string>::iterator it =  _alphaMap.find(character);
        if (it != _alphaMap.end()) {
            _textureToPrint.push_back(_alphaMap[character]);
        }
    }
}