/*
** EPITECH PROJECT, 2021
** organise_shop_items.c
** File description:
** RPG
*/

#include "header.h"

number_t *fill_shop_next_bag_num(int qtt, int spot)
{
    int x = 225;
    int y = 75 + (spot * 100);
    number_t *nbr = NULL;
    number_t *hold = NULL;

    nbr = malloc(sizeof(number_t));
    add_one_bag_num(nbr, x, y, qtt % 10);
    hold = nbr;
    for (int i = 10; i <= qtt; i = i * 10, hold = hold->next) {
        hold->next = malloc(sizeof(number_t));
        x = x - 10;
        add_one_bag_num(hold->next, x, y, (qtt / i) % 10);
    }
    hold->next = malloc(sizeof(number_t));
    add_one_bag_num(hold->next, x - 10, y, 10);
    return (nbr);
}

void add_shop_bag_nums(number_t **nums, int qtt, int spot)
{
    number_t *hold = *nums;

    if (!*nums) {
        *nums = fill_shop_next_bag_num(qtt, spot);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_shop_next_bag_num(qtt, spot);
    }
}

number_t *organise_shop_items(game_t *g)
{
    bag_t *hold = g->bag;
    number_t *nums = NULL;

    for (int i = 0; hold && hold->next && i < 6; hold = hold->next, i++) {
        hold->next->spr->crds.y = 75 + (i * 100);
        hold->next->spr->crds.x = 125;
        sfSprite_setPosition(hold->next->spr->spr, hold->next->spr->crds);
        add_shop_bag_nums(&nums, hold->next->quantity, i);
    }
    add_gold_nbr(&nums, g->player->gold, 1100, 650);
    return (nums);
}