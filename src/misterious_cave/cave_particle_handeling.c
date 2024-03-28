/*
** EPITECH PROJECT, 2021
** cave_particle_handeling.c
** File description:
** RPG
*/

#include "header.h"

void cave_particle_handeling(cave_t *cave, int delta)
{
    particle_t *hold = cave->particle;

    if (!cave->particle)
        return;
    for (; hold; hold = hold->next) {
        hold->spr->crds.y += delta * hold->spd;
        sfSprite_setPosition(hold->spr->spr, hold->spr->crds);
    }
    while (cave->particle && cave->particle->spr->crds.y > 200) {
        free_sprite(cave->particle->spr);
        cave->particle = cave->particle->next;
    }
    hold = cave->particle;
    for (; hold && hold->next; hold = hold->next)
        if (hold->next->spr->crds.y > 200) {
            free_sprite(hold->next->spr);
            hold->next = hold->next->next;
        }
}