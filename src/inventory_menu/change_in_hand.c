/*
** EPITECH PROJECT, 2021
** change_in_hand.c
** File description:
** RPG
*/

#include "header.h"

static void subtrace_one_of_selected(game_t *g, int id)
{
    bag_t *hold = g->bag;

    for (; hold && hold->next; hold = hold->next) {
        if (hold->next->id == id)
            hold->next->quantity -= 1;
        if (hold->next->quantity <= 0) {
            free_sprite(hold->next->spr);
            hold->next = hold->next->next;
        }
    }
}

static void reset_mh_check(game_t *g)
{
    if (g->bag->id) {
        add_item(g->bag, g->bag->id, 1);
        g->bag->id = 0;
        free_sprite(g->bag->spr);
        g->bag->spr = NULL;
        g->bag->quantity = 0;
    }
}

void change_in_hand(game_t *g, int id)
{
    if (g->bag->id == id) {
        add_item(g->bag, id, 1);
        g->bag->id = 0;
        free_sprite(g->bag->spr);
        g->bag->spr = NULL;
        g->bag->quantity = 0;
    } else {
        reset_mh_check(g);
        add_item(g->bag, id, 1);
        subtrace_one_of_selected(g, id);
    }
    mouse_reset(g->mouse);
}