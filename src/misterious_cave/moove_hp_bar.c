/*
** EPITECH PROJECT, 2021
** moove_hp_bar.c
** File description:
** RPG
*/

#include "header.h"

void moove_hp_bar(player_t *plr, sprite_t *spr)
{
    spr->r.left = 200 - (plr->hp * 200) / plr->max_hp;
    sfSprite_setTextureRect(spr->spr, spr->r);
}