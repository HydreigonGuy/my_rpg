/*
** EPITECH PROJECT, 2021
** walk.c
** File description:
** RPG
*/

#include "header.h"

void walk(player_t *p, int delta)
{
    if (p->dir.x > p->spr->crds.x) {
        p->spr->crds.x += delta * p->spd;
        if (p->dir.x < p->spr->crds.x)
            p->spr->crds.x = p->dir.x;
    } if (p->dir.x < p->spr->crds.x) {
        p->spr->crds.x -= delta * p->spd;
        if (p->dir.x > p->spr->crds.x)
            p->spr->crds.x = p->dir.x;
    } if (p->dir.y > p->spr->crds.y) {
        p->spr->crds.y += delta * p->spd;
        if (p->dir.y < p->spr->crds.y)
            p->spr->crds.y = p->dir.y;
    } if (p->dir.y < p->spr->crds.y) {
        p->spr->crds.y -= delta * p->spd;
        if (p->dir.y > p->spr->crds.y)
            p->spr->crds.y = p->dir.y;
    }
    p->spr->r.left = 200;
    sfSprite_setPosition(p->spr->spr, p->spr->crds);
}