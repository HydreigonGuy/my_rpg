/*
** EPITECH PROJECT, 2021
** purchase_check.c
** File description:
** RPG
*/

#include "header.h"

int get_shop_item_id(int shop_id)
{
    if (shop_id == 10)
        return (1);
    if (shop_id == 11)
        return (2);
    if (shop_id == 12)
        return (11);
    if (shop_id == 13)
        return (12);
    if (shop_id == 14)
        return (13);
}

int get_shop_item_price(int id)
{
    if (id == 1)
        return (3);
    if (id == 2)
        return (1);
    if (id == 11)
        return (5);
    if (id == 12)
        return (8);
    if (id == 13)
        return (15);
    return (0);
}

void play_transaction_sfx(game_t *g)
{
    sfSound_play(g->music->sound[3]->sound);
    sfSound_setVolume(g->music->sound[3]->sound, g->music->volume);
}

void purchase_check(game_t *g)
{
    int item_id = 0;

    if (g->state > 9 && g->state < 15) {
        item_id = get_shop_item_id(g->state);
        if (g->player->gold >= get_shop_item_price(item_id)) {
            add_item(g->bag, item_id, 1);
            g->player->gold -= get_shop_item_price(item_id);
            play_transaction_sfx(g);
        }
        g->state = 0;
        mouse_reset(g->mouse);
    }
    if (g->state >= 15 && g->state < 40) {
        sell_item(g);
        g->state = 0;
        mouse_reset(g->mouse);
    }
}