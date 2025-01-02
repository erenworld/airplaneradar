/*
** EPITECH PROJECT, 2024
** graphical - myradar
** File description:
** GET FILE SIZE
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/struct.h"

long get_size(const char *file)
{
    struct stat file_info;

    if (stat(file, &file_info) == 0) {
        return file_info.st_size;
    }
    return -1;
}
