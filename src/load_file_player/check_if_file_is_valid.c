/*
** EPITECH PROJECT, 2021
** check_if_file_is_valid.c
** File description:
** RPG
*/

#include "header.h"

int check_if_file_is_valid(char *str)
{
    int newl_count = 0;

    if (!str)
        return (1);
    for (int i = 0; str[i]; i++) {
        if (str[i + 1] == '\n' && (str[i] > '9' || str[i] < '0'))
            return (1);
        if (str[i] == '\n')
            newl_count++;
    }
    if (newl_count < 9)
        return (1);
    return (0);
}