/*
** EPITECH PROJECT, 2021
** city_can_interact.c
** File description:
** RPG
*/

#include "header.h"

int city_can_interact(sprite_t *spr)
{
    if (spr->crds.x > 700 && spr->crds.y < 300)
        return (1);
    if (spr->crds.x < 300 && spr->crds.y < 200)
        return (1);
    if (spr->crds.x < 400 && spr->crds.y > 350)
        return (1);
    return (0);
}