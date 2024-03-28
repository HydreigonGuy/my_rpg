/*
** EPITECH PROJECT, 2021
** add_fist.c
** File description:
** RPG
*/

#include "header.h"

attack_t *create_fist(player_t *plr)
{
    attack_t *hold = NULL;
    int x = plr->spr->crds.x + 35;
    int y = plr->spr->crds.y + 60;

    hold = malloc(sizeof(attack_t));
    hold->spr = fill_sprite("images/fist.png", x, y);
    fill_rect(hold->spr, 30, 30);
    hold->dir = plr->spr->r.top / 150;
    hold->spr->r.left = hold->dir * 30;
    sfSprite_setTextureRect(hold->spr->spr, hold->spr->r);
    hold->spd = plr->spd;
    hold->damage = plr->atk;
    hold->range = 100;
    hold->next = NULL;
    hold->allied = 1;
    return (hold);
}

void add_fist(attack_t **atk, player_t *plr)
{
    attack_t *hold = *atk;

    if (!*atk) {
        *atk = create_fist(plr);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = create_fist(plr);
    }
}