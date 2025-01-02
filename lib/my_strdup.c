/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** strdup
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
    int len = 0;
    char *tmp;
    int i = 0;

    if (src == NULL) {
        return NULL;
    }
    while (src[len] != '\0') {
        len++;
    }
    tmp = malloc(sizeof(char) * len + 1);
    if (tmp == NULL) {
        return NULL;
    }
    while (i <= len) {
        tmp[i] = src[i];
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}
