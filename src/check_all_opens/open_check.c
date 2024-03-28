/*
** EPITECH PROJECT, 2021
** open_check.c
** File description:
** RPG
*/

#include "header.h"

int open_check(char *str)
{
    int fd = open(str, O_RDONLY);

    if (fd == -1)
        return (1);
    close (fd);
    return (0);
}