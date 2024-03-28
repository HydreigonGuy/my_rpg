/*
** EPITECH PROJECT, 2021
** move_enemy.c
** File description:
** RPG
*/

#include "header.h"

int mv_not_in_rang(sprite_t *s1, sprite_t *s2)
{
    int x = s1->crds.x - s2->crds.x;
    int y = s1->crds.y - s2->crds.y;

    if (x * x + y * y < 20000)
        return (0);
    return (1);
}

void move_enemy_spr(sprite_t *plr, enemy_t *en, int delta)
{
    if (plr->crds.x > en->spr->crds.x) {
        en->spr->crds.x += delta * en->spd;
        en->spr->r.top = en->spr->r.height;
    } else if (plr->crds.x < en->spr->crds.x) {
        en->spr->crds.x -= delta * en->spd;
        en->spr->r.top = 0;
    }
    if (plr->crds.y > en->spr->crds.y)
        en->spr->crds.y += delta * en->spd / 2;
    else if (plr->crds.y < en->spr->crds.y)
        en->spr->crds.y -= delta * en->spd / 2;
    sfSprite_setPosition(en->spr->spr, en->spr->crds);
}

void move_enemy(sprite_t *plr, enemy_t *en, int delta, int t)
{
    enemy_t *hold = en;

    t = t / 1000;
    t = (t % 40) / 10;
    if (t == 3)
        t = 1;
    for (; hold; hold = hold->next) {
        if (mv_not_in_rang(plr, hold->spr))
            move_enemy_spr(plr, hold, delta);
        hold->spr->r.left = hold->spr->r.width * t;
        sfSprite_setTextureRect(hold->spr->spr, hold->spr->r);
        hold->cooldown -= delta;
    }
}