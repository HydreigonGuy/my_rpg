/*
** EPITECH PROJECT, 2021
** sell_item.c
** File description:
** RPG
*/

#include "header.h"

int get_other_item_price(int id)
{
    if (id == 23)
        return (1);
    if (id == 24)
        return (10);
    if (id == 26)
        return (30);
    return (0);
}

int get_item_price(int id)
{
    if (id == 1)
        return (2);
    if (id == 2)
        return (1);
    if (id == 11)
        return (2);
    if (id == 12)
        return (5);
    if (id == 13)
        return (10);
    if (id == 21)
        return (1);
    if (id == 22)
        return (1);
    return (get_other_item_price(id));
}

void sell_item(game_t *g)
{
    int quantity = 0;
    int id = get_sell_item_ig(g, &quantity);

    sfSound_play(g->music->sound[3]->sound);
    sfSound_setVolume(g->music->sound[3]->sound, g->music->volume);
    g->player->gold += get_item_price(id) * quantity;
}