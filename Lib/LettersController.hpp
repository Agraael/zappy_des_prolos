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
                {'A', "../Assets/letters/A_letter.png"},
                {'B', "../Assets/letters/B_letter.png"},
                {'C', "../Assets/letters/C_letter.png"},
                {'D', "../Assets/letters/D_letter.png"},
                {'E', "../Assets/letters/E_letter.png"},
                {'F', "../Assets/letters/F_letter.png"},
                {'G', "../Assets/letters/G_letter.png"},
                {'H', "../Assets/letters/H_letter.png"},
                {'I', "../Assets/letters/I_letter.png"},
                {'J', "../Assets/letters/J_letter.png"},
                {'K', "../Assets/letters/K_letter.png"},
                {'L', "../Assets/letters/L_letter.png"},
                {'M', "../Assets/letters/M_letter.png"},
                {'N', "../Assets/letters/N_letter.png"},
                {'O', "../Assets/letters/O_letter.png"},
                {'P', "../Assets/letters/P_letter.png"},
                {'Q', "../Assets/letters/Q_letter.png"},
                {'R', "../Assets/letters/R_letter.png"},
                {'S', "../Assets/letters/S_letter.png"},
                {'T', "../Assets/letters/T_letter.png"},
                {'U', "../Assets/letters/U_letter.png"},
                {'V', "../Assets/letters/V_letter.png"},
                {'W', "../Assets/letters/W_letter.png"},
                {'X', "../Assets/letters/X_letter.png"},
                {'Y', "../Assets/letters/Y_letter.png"},
                {'Z', "../Assets/letters/Z_letter.png"},
                {'1', "../Assets/letters/1_letter.png"},
                {'2', "../Assets/letters/2_letter.png"},
                {'3', "../Assets/letters/3_letter.png"},
                {'4', "../Assets/letters/4_letter.png"},
                {'5', "../Assets/letters/5_letter.png"},
                {'6', "../Assets/letters/6_letter.png"},
                {'7', "../Assets/letters/7_letter.png"},
                {'8', "../Assets/letters/8_letter.png"},
                {'9', "../Assets/letters/9_letter.png"},
                {'0', "../Assets/letters/0_letter.png"},
        };
    public:
        LetterController(const std::string &toPrint);
        ~LetterController() = default;
        void createVectorToPrint();
        std::vector<std::string> getVectorLetters() { return _textureToPrint; };
    };
}

#endif //LETTERSCONTROLLER_HPP
