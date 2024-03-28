/*
** EPITECH PROJECT, 2021
** fainting_fill.c
** File description:
** RPG
*/

#include "header.h"

sprite_t **fainting_fill(void)
{
    sprite_t **ret = NULL;

    ret = malloc(sizeof(sprite_t) * 2);
    ret[0] = fill_sprite("images/map.png", 0, 0);
    fill_rect(ret[0], 1400, 700);
    ret[1] = fill_sprite("images/space_to_respawn.png", 0, 600);
    ret[0]->r.top = 300;
    sfSprite_setTextureRect(ret[0]->spr, ret[0]->r);
    return (ret);
}