/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** struct.h
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

struct node {
    int x;
    int y;
    int radius;
    struct node *next;
};

#endif
