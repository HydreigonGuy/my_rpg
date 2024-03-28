/*
** EPITECH PROJECT, 2021
** spawn_enemy.c
** File description:
** RPG
*/

#include "header.h"

void spawn_enemy(enemy_t **e)
{
    enemy_t *hold = *e;

    if (*e == NULL) {
        *e = new_enemy();
    } else {
        for (hold; hold && hold->next; hold = hold->next);
        hold->next = new_enemy();
    }
}