/*
** EPITECH PROJECT, 2021
** rerect_spr.c
** File description:
** RPG
*/

#include "header.h"

void rerect_spr(int t, sprite_t *spr, int c)
{
    t = t /30000;
    for (int i = 0; i < c; i++)
        if (t % 40 >= (i * 40) / c)
            spr->r.left = i * spr->r.width;
    sfSprite_setTextureRect(spr->spr, spr->r);
}