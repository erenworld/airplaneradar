/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/

#include "../include/my.h"

void my_swap(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}
