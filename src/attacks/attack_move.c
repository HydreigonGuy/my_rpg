/*
** EPITECH PROJECT, 2021
** attack_move.c
** File description:
** RPG
*/

#include "header.h"

void attack_move(attack_t *atk, int delta)
{
    attack_t *hold = atk;

    for (; hold; hold = hold->next) {
        if (hold->dir == 0)
            hold->spr->crds.y += delta * hold->spd;
        if (hold->dir == 1)
            hold->spr->crds.x -= delta * hold->spd;
        if (hold->dir == 2)
            hold->spr->crds.x += delta * hold->spd;
        if (hold->dir == 3)
            hold->spr->crds.y -= delta * hold->spd;
        hold->range -= delta * hold->spd;
        if (hold->spd == 0)
            hold->range -= delta;
        sfSprite_setPosition(hold->spr->spr, hold->spr->crds);
    }
}