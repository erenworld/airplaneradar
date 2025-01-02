/*
** EPITECH PROJECT, 2024
** graphical - myradar
** File description:
** SIMPLE LINKED LIST
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/struct.h"

// TOWERLIST

struct node *create_node(int x, int y, int radius)
{
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
        exit(1);
    new_node->x = x;
    new_node->y = y;
    new_node->radius = radius;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node **head, int x, int y, int radius)
{
    struct node *new_node = create_node(x, y, radius);
    struct node *curr = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

int add(void *data, char **args)
{
    struct node **head = (struct node **)data;
    int i = 0;
    int x;
    int y;
    int radius;

    while (args[i] != NULL && args[i + 1] != NULL
        && args[i + 2] != NULL) {
        x = atoi(args[i]);
        y = atoi(args[i + 1]);
        radius = atoi(args[i + 2]);
        add_node(head, x, y, radius);
        i += 3;
    }
    return 0;
}

void free_three_part(char **threepart, int count)
{
    for (int k = 0; k < count; k++)
        free(threepart[k]);
    free(threepart);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

int check_error(char **three_part, int count)
{
    if (three_part == NULL || count != 4 || my_strcmp(three_part[0], "T") != 0)
        return 1;
    return 0;
}

struct node *get_tower_info(char *buffer)
{
    struct node *head = NULL;
    int i = 0;
    int count_tower = 0;
    char **tab = str_to_word_array(buffer);
    char **three_part;
    int count;
    int x;
    int y;
    int radius;

    if (tab == NULL)
        return NULL;
    for (int j = 0; tab[j] != NULL; j++) {
        three_part = str_to_word_array_s(tab[j]);
        count = 0;
        while (three_part[count] != NULL)
            count++;
        if (check_error(three_part, count) == 1) {
            free_three_part(three_part, count);
            continue;
        }
        x = atoi(three_part[1]);
        y = atoi(three_part[2]);
        radius = atoi(three_part[3]);
        add_node(&head, x, y, radius);
        count_tower++;
        free_three_part(three_part, count);
    }
    free_tab(tab);
    return head;
}
