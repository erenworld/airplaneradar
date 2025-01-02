/*
** EPITECH PROJECT, 2024
** graphical - myradar
** File description:
** MAIN FUNCTION
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/struct.h"


int my_radar(struct node *tower_list)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;

    // tower
    sfTexture *tx_tower;
    sfSprite **sp_towers;
    sfVector2f towers_size = {0.1f, 0.1f};
    int total_tower = 0;
    struct node *tmp = tower_list;
    
    while (tmp != NULL) {
        total_tower++;
        tmp = tmp->next;
    }

    sp_towers = malloc(sizeof(sfSprite *) * total_tower);
    if (!sp_towers)
        return 84;

    window = sfRenderWindow_create(mode, "MY RADAR", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    texture = sfTexture_createFromFile("./img/bggame.png", NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    tx_tower = sfTexture_createFromFile("./img/tower.png", NULL);
    if (!tx_tower)
        return EXIT_FAILURE;

    tmp = tower_list;
    for (int i = 0; i < total_tower; i++) {
        sp_towers[i] = sfSprite_create();
        sfSprite_setTexture(sp_towers[i], tx_tower, sfTrue);
        sfVector2f pos = {tmp->x, tmp->y};
        sfSprite_setPosition(sp_towers[i], pos);
        sfSprite_setScale(sp_towers[i], towers_size);
        tmp = tmp->next;
    }

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);

        for (int i = 0; i < total_tower; i++)
            sfRenderWindow_drawSprite(window, sp_towers[i], NULL);
            
        sfRenderWindow_display(window);
    }
    for (int i = 0; i < total_tower; i++) {
        sfSprite_destroy(sp_towers[i]);
    }
    free(sp_towers);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfTexture_destroy(tx_tower);
    sfRenderWindow_destroy(window);
    return 0;
}

int initial_data(const char *file, struct node **tower_list) 
{
    long size = get_size(file);
    if (size == -1)
        return 84;
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        my_putstr("ERROR - CANNOT OPEN YOUR FILE");
        return 84;
    }
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        my_putstr("ALLOCATION FAILED");
        close(fd);
        return 84;
    }
    long reader = read(fd, buffer, size);
    buffer[reader] = '\0';
    *tower_list = get_tower_info(buffer);
    free(buffer);
    close(fd);
    return 0;
}

int main(int argc, char **argv) 
{
    if (argc < 2) {
        my_putstr("Error: Missing filename argument");
        return 84;
    }

    struct node *tower_list = NULL;
    int result = initial_data(argv[1], &tower_list);
    if (result != 0) {
        return result;
    }

    my_radar(tower_list);

    while (tower_list != NULL) {
        struct node *tmp = tower_list;
        tower_list = tower_list->next;
        free(tmp);
    }

    return 0;
}


