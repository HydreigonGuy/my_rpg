/*
** EPITECH PROJECT, 2021
** free_cave.c
** File description:
** RPG
*/

#include "header.h"

void free_cave(cave_t *cave)
{
    for (int i = 0; i < 8; i++)
        free_sprite(cave->scene->spr[i]);
    free(cave->scene);
    for (; cave->enemy; cave->enemy = cave->enemy->next)
        free_sprite(cave->enemy->spr);
    for (; cave->particle; cave->particle = cave->particle->next)
        free_sprite(cave->particle->spr);
    free(cave);
}