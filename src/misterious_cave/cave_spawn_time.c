/*
** EPITECH PROJECT, 2021
** cave_spawn_time.c
** File description:
** RPG
*/

#include "header.h"

int cave_spawn_time(cave_t *cave)
{
    sfTime t = sfClock_getElapsedTime(cave->clock);

    if (t.microseconds / 30000 > 200) {
        sfClock_restart(cave->clock);
        return (1);
    }
    if (t.microseconds / 3000 > 500 && cave->e_count == 0) {
        sfClock_restart(cave->clock);
        return (1);
    }
    return (0);
}