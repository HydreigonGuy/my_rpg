/*
** EPITECH PROJECT, 2021
** forest_fill.c
** File description:
** RPG
*/

#include "header.h"

sprite_t **fill_forset_spr(void)
{
    sprite_t **ret = NULL;

    ret = malloc(sizeof(sprite_t *) * 4);
    ret[0] = fill_sprite("images/scene2.png", 0, 0);
    ret[1] = fill_sprite("images/interact.png", 800, 650);
    ret[2] = fill_sprite("images/player_view.png", 990, 600);
    ret[3] = fill_sprite("images/player_hp_bar.png", 995, 685);
    fill_rect(ret[3], 200, 10);
    return (ret);
}

forest_t *forest_fill(void)
{
    forest_t *ret = NULL;

    ret = malloc(sizeof(forest_t));
    ret->forest = fill_forset_spr();
    ret->tree = NULL;
    ret->particle = NULL;
    return (ret);
}