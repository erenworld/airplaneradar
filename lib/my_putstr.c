/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/
#include "../include/my.h"

void my_putstr(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        my_putchar(str[i]);
    }
}
