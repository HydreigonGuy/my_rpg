/*
** EPITECH PROJECT, 2021
** move_cinematic_spr.c
** File description:
** RPG
*/

#include "header.h"

static void move_fainted_dragon(sprite_t *spr, int delta, int angle)
{
    angle = angle % 360;
    if (angle < 90 || angle >= 270)
        spr->crds.y -= delta * 12;
    if (angle >= 90 && angle < 270)
        spr->crds.y += delta * 12;
    if (spr->crds.y < 100)
        spr->crds.y = 100;
    if (spr->crds.y > 600)
        spr->crds.y = 600;
}

void move_cinematic_spr(sprite_t **spr, sfVector2f *scale, float *angl, int d)
{
    if (spr[0]->crds.x >= -400) {
        *angl += d * 2;
        scale->x += d * 0.003;
        scale->y += d * 0.003;
        spr[0]->crds.x -= d * 3;
        spr[0]->crds.y -= d * 3;
        move_fainted_dragon(spr[1], d, *angl);
        sfSprite_setPosition(spr[1]->spr, spr[1]->crds);
        sfSprite_setPosition(spr[0]->spr, spr[0]->crds);
        sfSprite_setRotation(spr[1]->spr, *angl);
        sfSprite_setScale(spr[0]->spr, *scale);
    }
}