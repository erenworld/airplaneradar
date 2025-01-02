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

void start_game(sfRenderWindow *window)
{
    int is_alive = 1;
    int offset = 110;
    person_t my_ducks;
    resources_t *res = malloc(sizeof(resources_t));

    res->speed = 4.0;
    my_resources(res, window);
    my_ducks = (person_t){res->sp_duck, res->tx_duck, {0.0, 200.0}};
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &res->event)) {
            is_event_closed(window, res->event);
            kill_duck(res, window, &is_alive);
        }
        others(res, &is_alive, offset, &my_ducks);
    }
    destroyer(res);
    free(res);
}
