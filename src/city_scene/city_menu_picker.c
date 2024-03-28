/*
** EPITECH PROJECT, 2021
** city_menu_picker.c
** File description:
** RPG
*/

#include "header.h"

void city_menu_picker(game_t *g, sprite_t *spr)
{
    if (g->player->spr->crds.x > 700 && g->player->spr->crds.y < 300)
        shop_menu(g, spr);
    if (g->player->spr->crds.x < 300 && g->player->spr->crds.y < 200)
        quests_menu(g, spr);
    if (g->player->spr->crds.x < 400 && g->player->spr->crds.y > 350)
        travel_menu(g, spr);
}