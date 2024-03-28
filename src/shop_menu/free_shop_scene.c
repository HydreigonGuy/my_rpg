/*
** EPITECH PROJECT, 2021
** free_shop_scene.c
** File description:
** RPG
*/

#include "header.h"

void free_shop_scene(scene_t *shop)
{
    for (int i = 0; i < 17; i++) {
        free_sprite(shop->btn[i]->spr);
        free(shop->btn[i]);
    }
    free(shop->btn);
    free_sprite(shop->spr[0]);
    free_sprite(shop->spr[1]);
    free(shop->spr);
    free(shop);
}