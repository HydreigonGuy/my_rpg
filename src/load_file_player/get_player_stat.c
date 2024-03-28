/*
** EPITECH PROJECT, 2021
** get_player_stat.c
** File description:
** RPG
*/

#include "header.h"

int get_player_stat(char *stats, int stat_num)
{
    int ret = 0;
    int c = 0;

    for (; ret != stat_num && stats[c]; c++)
        if (stats[c] == '\n')
            ret += 1;
    c++;
    ret = 0;
    while (stats[c] != '\n' && stats[c] != '\0') {
        if (stats[c] <= '9' && stats[c] >= '0')
            ret = ret * 10 + stats[c] - '0';
        c++;
    }
    return (ret);
}