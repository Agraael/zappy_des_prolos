//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#ifndef LETTERSCONTROLLER_HPP
#define LETTERSCONTROLLER_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

namespace graphic {
    class LetterController {
        std::string _toPrint;
        std::vector<std::string> _textureToPrint;
        std::unordered_map<char, std::string> _alphaMap = {
                {'A', "../Assets/A_letter.png"},
                {'B', "../Assets/B_letter.png"},
                {'C', "../Assets/C_letter.png"},
                {'D', "../Assets/D_letter.png"},
                {'E', "../Assets/E_letter.png"},
                {'F', "../Assets/F_letter.png"},
                {'G', "../Assets/G_letter.png"},
                {'H', "../Assets/H_letter.png"},
                {'I', "../Assets/I_letter.png"},
                {'J', "../Assets/J_letter.png"},
                {'K', "../Assets/K_letter.png"},
                {'L', "../Assets/L_letter.png"},
                {'M', "../Assets/M_letter.png"},
                {'N', "../Assets/N_letter.png"},
                {'O', "../Assets/O_letter.png"},
                {'P', "../Assets/P_letter.png"},
                {'Q', "../Assets/Q_letter.png"},
                {'R', "../Assets/R_letter.png"},
                {'S', "../Assets/S_letter.png"},
                {'T', "../Assets/T_letter.png"},
                {'U', "../Assets/U_letter.png"},
                {'V', "../Assets/V_letter.png"},
                {'W', "../Assets/W_letter.png"},
                {'X', "../Assets/X_letter.png"},
                {'Y', "../Assets/Y_letter.png"},
                {'Z', "../Assets/Z_letter.png"},
                {'1', "../Assets/1_letter.png"},
                {'2', "../Assets/2_letter.png"},
                {'3', "../Assets/3_letter.png"},
                {'4', "../Assets/4_letter.png"},
                {'5', "../Assets/5_letter.png"},
                {'6', "../Assets/6_letter.png"},
                {'7', "../Assets/7_letter.png"},
                {'8', "../Assets/8_letter.png"},
                {'9', "../Assets/9_letter.png"},
                {'0', "../Assets/0_letter.png"},
        };
    public:
        LetterController(const std::string &toPrint);
        ~LetterController() = default;
        void createVectorToPrint();
        std::vector<std::string> getVectorLetters() { return _textureToPrint; };
    };
}

#endif //LETTERSCONTROLLER_HPP
