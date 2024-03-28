/*
** EPITECH PROJECT, 2021
** atk_lair_collision_check.c
** File description:
** RPG
*/

#include "header.h"

int atck_hits_dragon(attack_t *atk, sprite_t *spr, lair_t *lair)
{
    if (870 <= atk->spr->crds.x &&
        spr->crds.y <= atk->spr->crds.y + atk->spr->r.height &&
        spr->crds.y + 300 >= atk->spr->crds.y) {
        lair->hp -= atk->damage;
        return (1);
    }
    return (0);
}

void atk_lair_collision_check(game_t *g, lair_t *lair)
{
    attack_t *hold = lair->atk;

    for (; hold; hold = hold->next) {
        if (hold->allied && atck_hits_dragon(hold, lair->dragon, lair))
            hold->range = -1;
        else if (!hold->allied && atck_hits_plr(hold, g->player))
            hold->range = -1;
    }
}