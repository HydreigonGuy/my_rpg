/*
** EPITECH PROJECT, 2021
** use_selected_item.c
** File description:
** RPG
*/

#include "header.h"

void use_selected_item(game_t *g, bag_scene_t *inv)
{
    bag_t *hold = g->bag;

    g->state = 0;
    if (inv->select == 1)
        g->player->atk += 1;
    if (inv->select == 2)
        g->player->hp += 5;
    if (g->player->hp > g->player->max_hp)
        g->player->hp = g->player->max_hp;
    mouse_reset(g->mouse);
    for (; hold && hold->next; hold = hold->next) {
        if (hold->next->id == inv->select)
            hold->next->quantity -= 1;
        if (hold->next->quantity <= 0) {
            free_sprite(hold->next->spr);
            hold->next = hold->next->next;
            inv->select = 0;
        }
    }
    inv->nbr = organise_inventory_items(g);
}