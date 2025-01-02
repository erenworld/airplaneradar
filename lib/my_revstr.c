/*
** EPITECH PROJECT, 2024
** day07
** File description:
** revstr
*/
#include "../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int k = len - 1;

    for (int i = 0; i < len / 2; i++) {
        my_swap(&str[i], &str[k]);
        k--;
    }
    return str;
}
