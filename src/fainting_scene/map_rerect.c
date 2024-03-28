/*
** EPITECH PROJECT, 2021
** map_rerect.c
** File description:
** RPG
*/

#include "header.h"

void prevent_map_from_sinking(sprite_t *map)
{
    if (map->r.top < 0)
        map->r.top = 0;
    if (map->r.top > 300)
        map->r.top = 300;
}

void map_rerect(int delta, sprite_t *map)
{
    if (map->r.top == 300) {
        map->r.left += delta;
        if (map->r.left >= 800) {
            map->r.left = 800;
        }
    }
    if (map->r.top == 0) {
        map->r.left -= delta;
        if (map->r.left <= 0) {
            map->r.left = 0;
        }
    }
    if (map->r.left == 0)
        map->r.top += delta;
    if (map->r.left == 800)
        map->r.top -= delta;
    prevent_map_from_sinking(map);
    sfSprite_setTextureRect(map->spr, map->r);
}