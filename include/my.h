/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "./struct.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY_H_
    #define MY_H_

struct node *get_tower_info(char *buffer);
long get_size(const char *file);
int main(int argc, char **argv);
int my_radar(struct node *tower_list);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
int my_put_nbr(int nb);
void my_swap(char *a, char *b);
int my_strlen(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
char *my_strdup(const char *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char **str_to_word_array(char *str);
char **str_to_word_array_s(char *str);

#endif
