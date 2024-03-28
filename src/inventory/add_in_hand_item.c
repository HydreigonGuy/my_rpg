/*
** EPITECH PROJECT, 2021
** add_in_hand_item.c
** File description:
** RPG
*/

#include "header.h"

void add_in_hand_item(bag_t *bag, int id)
{
    bag->id = id;
    bag->quantity = 1;
    bag->spr = fill_sprite(get_item_spr(id), 0, 0);
}