/*
** EPITECH PROJECT, 2018
** utils
** File description:
** source
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool    is_str_digit(char *str)
{
        if (str == NULL)
                return (false);
        for (size_t i = 0; str[i] != '\0'; ++i) {
                if (isdigit(str[i]) == false)
                        return (false);
        }
        return (true);
}