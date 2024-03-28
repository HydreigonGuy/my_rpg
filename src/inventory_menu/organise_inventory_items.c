/*
** EPITECH PROJECT, 2021
** organise_inventory_items.c
** File description:
** RPG
*/

#include "header.h"

number_t *organise_inventory_items(game_t *g)
{
    bag_t *hold = g->bag;
    number_t *nums = NULL;

    if (hold->spr) {
        hold->spr->crds.y = 175;
        hold->spr->crds.x = 325;
        sfSprite_setPosition(hold->spr->spr, hold->spr->crds);
        add_bag_nums(&nums, hold->quantity, 0);
    }
    for (int i = 1; hold && hold->next; hold = hold->next, i++) {
        hold->next->spr->crds.y = 175 + (i / 6) * 100;
        hold->next->spr->crds.x = 325 + (i % 6) * 100;
        sfSprite_setPosition(hold->next->spr->spr, hold->next->spr->crds);
        add_bag_nums(&nums, hold->next->quantity, i);
    }
    add_bag_nums(&nums, g->player->gold, -1);
    add_stats_nums(&nums, g->player);
    return (nums);
}