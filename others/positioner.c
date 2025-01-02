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

void positioner(resources_t *res)
{
    sfVector2f shooter_div_pos = {280, 20};
    sfVector2f taille_bg = {1, 1};
    sfVector2f taille_btn = {0.89, 0.89};
    sfVector2f position_btn = {550, 700};

    sfSprite_setScale(res->btn, taille_btn);
    sfSprite_setPosition(res->btn, position_btn);
    sfSprite_setScale(res->sprite, taille_bg);
    sfSprite_setPosition(res->sp_shooter, shooter_div_pos);
}
