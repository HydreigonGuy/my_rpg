/*
** EPITECH PROJECT, 2021
** delta_fill.c
** File description:
** RPG
*/

#include "header.h"

int delta_fill(game_t *game)
{
    sfTime new_time = sfClock_getElapsedTime(game->clock);
    int delta = (new_time.microseconds - game->time.microseconds) / 30000;

    game->time = new_time;
    return (delta);
}