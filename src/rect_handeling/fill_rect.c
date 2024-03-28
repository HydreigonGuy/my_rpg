/*
** EPITECH PROJECT, 2021
** fill_rect.c
** File description:
** RPG
*/

#include "header.h"

void fill_rect(sprite_t *spr, int x, int y)
{
    spr->r.top = 0;
    spr->r.left = 0;
    spr->r.width = x;
    spr->r.height = y;
    sfSprite_setTextureRect(spr->spr, spr->r);
}