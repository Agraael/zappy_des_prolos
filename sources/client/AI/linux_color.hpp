/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 13/06/18
*/

#ifndef PATHFINDER_A_LINUX_COLOR_HPP
#define PATHFINDER_A_LINUX_COLOR_HPP

#include <string>
#include <unordered_map>
#include <bits/unordered_map.h>
#include <iostream>

namespace Linux
{
	enum class TermColor {
		BLACK_BG, BLACK_FG,
		RED_BG, RED_FG,
		GREEN_BG, GREEN_FG,
		YELLOW_BG, YELLOW_FG,
		BLUE_BG, BLUE_FG,
		MAGENTA_BG, MAGENTA_FG,
		CYAN_BG, CYAN_FG,
		WHITE_BG, WHITE_FG,
		RESET,
		BOLD_ON, BOLD_OFF,
		UNDERLINE_ON, UNDERLINE_OFF,
		INVERSE_ON, INVERSE_OFF
	};

	inline void color(TermColor clr) noexcept
	{
		static const std::unordered_map<TermColor, std::string> colorMap = {
			{TermColor::BLACK_FG, "30"}, {TermColor::BLACK_BG, "40"},
			{TermColor::RED_FG, "31"}, {TermColor::RED_BG, "41"},
			{TermColor::GREEN_FG, "32"}, {TermColor::GREEN_BG, "42"},
			{TermColor::YELLOW_FG, "33"}, {TermColor::YELLOW_BG, "43"},
			{TermColor::BLUE_FG, "34"}, {TermColor::BLUE_BG, "44"},
			{TermColor::MAGENTA_FG, "35"}, {TermColor::MAGENTA_BG, "45"},
			{TermColor::CYAN_FG, "36"}, {TermColor::CYAN_BG, "46"},
			{TermColor::WHITE_FG, "37"}, {TermColor::WHITE_BG, "47"},
			{TermColor::RESET, "0"},
			{TermColor::BOLD_ON, "1"}, {TermColor::BOLD_OFF, "21"},
			{TermColor::UNDERLINE_ON, "4"}, {TermColor::UNDERLINE_OFF, "24"},
			{TermColor::INVERSE_ON, "7"}, {TermColor::INVERSE_OFF, "27"},
		};
		std::cout << "\033[" + colorMap.at(clr) + "m";
	}
}

#endif //PATHFINDER_A_LINUX_COLOR_HPP
