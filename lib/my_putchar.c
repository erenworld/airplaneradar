/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/
#include "../include/my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}