/*
** EPITECH PROJECT, 2021
** city_fill.c
** File description:
** RPG
*/

#include "header.h"

scene_t *city_fill(void)
{
    scene_t *ret = NULL;

    ret = malloc(sizeof(scene_t));
    ret->spr = malloc(sizeof(sprite_t *) * 4);
    ret->spr[0] = fill_sprite("images/city_bg.png", 0, 0);
    ret->spr[1] = fill_sprite("images/interact.png", 800, 650);
    ret->spr[2] = fill_sprite("images/player_view.png", 990, 600);
    ret->spr[3] = fill_sprite("images/player_hp_bar.png", 995, 685);
    fill_rect(ret->spr[3], 200, 10);
    return (ret);
}