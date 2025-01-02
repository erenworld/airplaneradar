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

void my_resources(resources_t *res, sfRenderWindow *window)
{
    sfVector2f start_duck = {0.0, 200.0};

    res->window = window;
    res->game_bg = sfTexture_createFromFile("./img/bggame.png", NULL);
    res->game_sprite = sfSprite_create();
    res->tx_cursor = sfTexture_createFromFile("./img/shootcursor.png", NULL);
    res->sp_cursor = sfSprite_create();
    res->tx_duck = sfTexture_createFromFile("./img/plane.png", NULL);
    res->sp_duck = sfSprite_create();
    res->rect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTexture(res->game_sprite, res->game_bg, sfTrue);
    sfSprite_setTexture(res->sp_cursor, res->tx_cursor, sfTrue);
    sfSprite_setTexture(res->sp_duck, res->tx_duck, sfTrue);
    sfSprite_setTextureRect(res->sp_duck, res->rect);
    sfSprite_setPosition(res->sp_duck, start_duck);
}
