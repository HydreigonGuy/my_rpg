/*
** EPITECH PROJECT, 2021
** forest_particle_handeling.c
** File description:
** RPG
*/

#include "header.h"

void forest_particle_handeling(forest_t *f, int delta)
{
    particle_t *hold = f->particle;

    if (!f->particle)
        return;
    for (; hold; hold = hold->next) {
        hold->spr->crds.y += delta * hold->spd;
        sfSprite_setPosition(hold->spr->spr, hold->spr->crds);
    }
    while (f->particle && f->particle->spr->crds.y > 700) {
        free_sprite(f->particle->spr);
        f->particle = f->particle->next;
    }
    hold = f->particle;
    for (; hold && hold->next; hold = hold->next)
        if (hold->next->spr->crds.y > 700) {
            free_sprite(hold->next->spr);
            hold->next = hold->next->next;
        }
}