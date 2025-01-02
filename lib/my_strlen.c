/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int index = 0;
    int length = 0;

    if (!str) {
        my_putstr("Error: NULL pointer passed to my_strlen\n");
        return 84;
    }
    while (str[index] != '\0') {
        length++;
        index++;
    }
    return length;
}
