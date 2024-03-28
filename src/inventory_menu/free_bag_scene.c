/*
** EPITECH PROJECT, 2021
** free_bag_scene.c
** File description:
** RPG
*/

#include "header.h"

void free_bag_scene(bag_scene_t *inv)
{
    free_sprite(inv->board);
    for (; inv->nbr; inv->nbr = inv->nbr->next)
        free_sprite(inv->nbr->spr);
    free_sprite(inv->btn[0]->spr);
}