/*
** EPITECH PROJECT, 2024
** graphical
** File description:
** project my hunter
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void move_character(person_t *duck, float speed)
{
    duck->position.x += speed;
    if (duck->position.x > 1900) {
        duck->position.x = 0;
        duck->position.y = (float)(rand() % 800);
    }
    sfSprite_setPosition(duck->sprite, duck->position);
}
