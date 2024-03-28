/*
** EPITECH PROJECT, 2021
** player_in_screen.c
** File description:
** RPG
*/

#include "header.h"

void player_in_screen(player_t *p, int scene, int mv)
{
    if (p->dir.x < 0)
        p->dir.x = 0;
    if (p->dir.y < 0)
        p->dir.y = 0;
    if (p->dir.x > 1200 - p->spr->r.width)
        p->dir.x = 1200 - p->spr->r.width;
    if (p->dir.y > 700 - p->spr->r.height)
        p->dir.y = 700 - p->spr->r.height;
    if (scene == 1)
        city_in_screen(p, mv);
    if (scene == 2)
        cave_in_screen(p, mv);
    if (scene == 3)
        frst_in_screen(p, mv);
}