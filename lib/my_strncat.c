/*
** EPITECH PROJECT, 2024
** day07
** File description:
** strncat
*/
#include "../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; src[i] != '\0' && i < nb; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
