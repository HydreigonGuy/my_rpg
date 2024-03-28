/*
** EPITECH PROJECT, 2021
** forest_can_interact.c
** File description:
** RPG
*/

#include "header.h"

int forest_can_interact(sprite_t *spr)
{
    if (spr->crds.x < 400 && spr->crds.y > 350)
        return (1);
    return (0);
}