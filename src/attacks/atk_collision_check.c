/*
** EPITECH PROJECT, 2021
** atk_collision_check.c
** File description:
** RPG
*/

#include "header.h"

int atck_hits_enemy(attack_t *atk, enemy_t *en)
{
    enemy_t *hold = en;

    for (; hold; hold = hold->next) {
        if (hold->spr->crds.x <= atk->spr->crds.x + atk->spr->r.width &&
            hold->spr->crds.x + hold->spr->r.width >= atk->spr->crds.x &&
            hold->spr->crds.y <= atk->spr->crds.y + atk->spr->r.height &&
            hold->spr->crds.y + hold->spr->r.height >= atk->spr->crds.y) {
                hold->hp -= atk->damage;
                return (1);
            }
    }
    return (0);
}

int atck_hits_plr(attack_t *atk, player_t *plr)
{
    if (plr->spr->crds.x <= atk->spr->crds.x + atk->spr->r.width &&
        plr->spr->crds.x + plr->spr->r.width >= atk->spr->crds.x &&
        plr->spr->crds.y <= atk->spr->crds.y + atk->spr->r.height &&
        plr->spr->crds.y + plr->spr->r.height >= atk->spr->crds.y) {
        plr->hp -= atk->damage;
        return (1);
    }
    return (0);
}

void atk_collision_check(game_t *g, cave_t *c)
{
    attack_t *hold = c->atks;

    for (; hold; hold = hold->next) {
        if (hold->allied && atck_hits_enemy(hold, c->enemy) && hold->spd)
            hold->range = -1;
        else if (!hold->allied && atck_hits_plr(hold, g->player))
            hold->range = -1;
    }
}