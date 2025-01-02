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

void is_event_closed(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void drawer(resources_t *res, sfRenderWindow *window, int *is_alive)
{
    sfRenderWindow_drawSprite(window, res->game_sprite, NULL);
    if (*is_alive)
        sfRenderWindow_drawSprite(window, res->sp_duck, NULL);
    sfRenderWindow_drawSprite(window, res->sp_cursor, NULL);
}

int kill_duck(resources_t *res, sfRenderWindow *window, int *is_alive)
{
    sfFloatRect duck_bounds = sfSprite_getGlobalBounds(res->sp_duck);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (*is_alive && res->event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&duck_bounds, mouse_pos.x, mouse_pos.y)) {
            *is_alive = 0;
            res->speed += 2;
            sfSprite_setPosition(res->sp_duck, (sfVector2f){-100, -100});
            return 0;
        }
    }
    return 84;
}

void move_rect(resources_t *res, int offset)
{
    sfTexture *texture = (sfTexture *)sfSprite_getTexture(res->sp_duck);
    sfVector2u tx_size = sfTexture_getSize(texture);
    sfIntRect rect = sfSprite_getTextureRect(res->sp_duck);

    rect.left += offset;
    if (rect.left >= tx_size.x - offset) {
        rect.left = 0;
    }
    sfSprite_setTextureRect(res->sp_duck, rect);
}

void others(resources_t *res, int *is_alive, int offset, person_t *my_ducks)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(res->window);
    sfVector2f mouse_pos = {(float)mouse.x, (float)mouse.y};

    move_rect_and_duck(res, is_alive, offset, my_ducks);
    sfSprite_setPosition(res->sp_cursor, mouse_pos);
    sfRenderWindow_clear(res->window, sfWhite);
    drawer(res, res->window, is_alive);
    sfRenderWindow_display(res->window);
}
