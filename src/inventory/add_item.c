/*
** EPITECH PROJECT, 2021
** add_item.c
** File description:
** RPG
*/

#include "header.h"

void add_in_inventory(bag_t *bag, int item_id, int quantity)
{
    bag_t *hold = bag;

    for (; hold->next && hold->next->id != item_id; hold = hold->next);
    if (hold->next) {
        hold->next->quantity += quantity;
    } else {
        hold->next = malloc(sizeof(bag_t));
        hold->next->id = item_id;
        hold->next->quantity = quantity;
        hold->next->next = NULL;
        hold->next->spr = fill_sprite(get_item_spr(item_id), 0, 0);
    }
}

int get_random_weapon_id(void)
{
    if (rand() % 7 != 5)
        return (11);
    if (rand() % 7 != 4)
        return (12);
    return (13);
}

void add_item(bag_t *bag, int item_id, int quantity)
{
    if (quantity <= 0)
        return;
    if (item_id == 25)
        item_id = get_random_weapon_id();
    if (bag->id == 0 && item_id < 20 && item_id > 10)
        add_in_hand_item(bag, item_id);
    else
        add_in_inventory(bag, item_id, quantity);
}