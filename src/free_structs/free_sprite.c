/*
** EPITECH PROJECT, 2021
** free_sprite.c
** File description:
** RPG
*/

#include "header.h"

void free_sprite(sprite_t *spr)
{
    sfSprite_destroy(spr->spr);
    sfTexture_destroy(spr->txtr);
    free(spr);
}