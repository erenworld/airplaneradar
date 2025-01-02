/*
** EPITECH PROJECT, 2024
** str to word array (for space)
** File description:
** magic function
*/

#include "../include/my.h"

int counters(char *str)
{
    int result = 0;
    int skip = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            skip = 0;
            continue;
        }
        if (!skip) {
            result++;
            skip = 1;
        }
    }
    return result;
}

char **str_to_word_array_s(char *str)
{
    int str_len = my_strlen(str);
    int total_words = counters(str);
    int word_start = 0;
    int word_index = 0;
    char **tab = malloc(sizeof(char *) * (total_words + 1));
    int each_len;

    for (int i = 0; i <= str_len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            each_len = i - word_start;
            tab[word_index] = malloc(sizeof(char) * (each_len + 1));
            my_strncpy(tab[word_index], str + word_start, each_len);
            tab[word_index][each_len] = '\0';
            word_index++;
            word_start = i + 1;
        }
    }
    tab[word_index] = NULL;
    return tab;
}
