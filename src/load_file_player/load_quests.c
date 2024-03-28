/*
** EPITECH PROJECT, 2021
** load_quests.c
** File description:
** RPG
*/

#include "header.h"

int *load_quests(char *stats)
{
    int *ret = NULL;

    ret = malloc(sizeof(int) * 3);
    ret[0] = get_player_stat(stats, 7);
    ret[1] = get_player_stat(stats, 8);
    ret[2] = get_player_stat(stats, 9);
    return (ret);
}