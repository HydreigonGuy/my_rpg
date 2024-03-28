/*
** EPITECH PROJECT, 2021
** item_select_check.c
** File description:
** RPG
*/

#include "header.h"

int selected_item(mouse_t *m, sprite_t *spr)
{
    if (!spr)
        return (0);
    if (spr->crds.x > m->r_x)
        return (0);
    if (spr->crds.x + spr->r.width < m->r_x)
        return (0);
    if (spr->crds.y > m->r_y)
        return (0);
    if (spr->crds.y + spr->r.height < m->r_y)
        return (0);
    return (1);
}

void item_select_check(game_t *g, bag_scene_t *inv)
{
    bag_t *hold = g->bag;

    inv->display_use = 0;
    if (g->state == 10 && selected_is_usable(inv->select))
        use_selected_item(g, inv);
    for (; hold; hold = hold->next)
        if (selected_item(g->mouse, hold->spr))
            inv->select = hold->id;
    if (inv->select && selected_is_weapond(inv->select)) {
        change_in_hand(g, inv->select);
        inv->nbr = organise_inventory_items(g);
        inv->select = 0;
    }
    if (inv->select && selected_is_usable(inv->select))
        inv->display_use = 1;
    if (g->state == 10)
        g->state = 0;
}