/*
** EPITECH PROJECT, 2021
** get_sell_item_ig.c
** File description:
** RPG
*/

#include "header.h"

void check_for_last_item(bag_t *bag)
{
    if (bag->next->quantity == 0) {
        free_sprite(bag->next->spr);
        bag->next = bag->next->next;
    }
}

int get_sell_item_ig(game_t *g, int *qtt)
{
    int spot = (g->state - 15) / 2;
    bag_t *hold = g->bag;
    int id = 0;

    *qtt = 0;
    for (int i = 0; i < spot && hold->next; i++, hold = hold->next);
    if (!hold->next)
        return (0);
    if (g->state % 2 == 1) {
        *qtt = 1;
        id = hold->next->id;
        hold->next->quantity = hold->next->quantity - 1;
        check_for_last_item(hold);
    } else {
        *qtt = hold->next->quantity;
        id = hold->next->id;
        free_sprite(hold->next->spr);
        hold->next = hold->next->next;
    }
    return (id);
}