/*
** EPITECH PROJECT, 2021
** add_weapond_atk.c
** File description:
** RPG
*/

#include "header.h"

char *get_weapond_file(int id)
{
    if (id == 11)
        return ("images/dagger_atk.png");
    if (id == 12)
        return ("images/spear_atk.png");
    if (id == 13)
        return ("images/axe_atk.png");
}

void handle_weapon_spr(attack_t *atk, int x, int y, int id)
{
    int add = 0;

    if (id == 11)
        add = 100;
    if (id == 12)
        add = 200;
    if (id == 13)
        add = 150;
    atk->spr = fill_sprite(get_weapond_file(id), x - add + 50, y - add + 100);
    fill_rect(atk->spr, add * 2, add * 2);
    sfSprite_setTextureRect(atk->spr->spr, atk->spr->r);
}

attack_t *create_w_attack(int id, player_t *plr)
{
    attack_t *hold = NULL;
    int x = plr->spr->crds.x;
    int y = plr->spr->crds.y;

    hold = malloc(sizeof(attack_t));
    hold->dir = 0;
    hold->spd = 0;
    handle_weapon_spr(hold, x, y, id);
    hold->damage = plr->atk + (id - 10) * 2;
    hold->range = 20;
    hold->next = NULL;
    hold->allied = 1;
    return (hold);
}

void add_weapond_atk(game_t *g, attack_t **atk)
{
    attack_t *hold = *atk;

    if (!*atk) {
        *atk = create_w_attack(g->bag->id, g->player);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = create_w_attack(g->bag->id, g->player);
    }
}