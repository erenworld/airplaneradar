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

void creator(resources_t *res)
{
    res->btn = sfSprite_create();
    res->texture_start_btn =
    sfTexture_createFromFile("./img/startbtn.png", NULL);
    res->sp_shooter = sfSprite_create();
    res->tx_shooter = sfTexture_createFromFile("./img/bggg.png", NULL);
}
