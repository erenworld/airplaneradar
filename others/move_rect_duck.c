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

void move_rect_and_duck(resources_t *res, int *is_alive, int offset,
    person_t *my_ducks)
{
    if (*is_alive) {
        // move_rect(res, offset);
        move_character(my_ducks, res->speed);
    } else {
        *is_alive = 1;
        my_ducks->position = (sfVector2f){-80.0, (float)(rand() % 800)};
        sfSprite_setPosition(my_ducks->sprite, my_ducks->position);
    }
}
