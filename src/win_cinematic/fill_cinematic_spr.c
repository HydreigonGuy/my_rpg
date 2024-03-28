/*
** EPITECH PROJECT, 2021
** fill_cinematic_spr.c
** File description:
** RPG
*/

#include "header.h"

sprite_t **fill_cinematic_spr(void)
{
    sprite_t **spr = NULL;

    spr = malloc(sizeof(sprite_t *) * 3);
    spr[0] = fill_sprite("images/flawwwwless.png", 0, 0);
    spr[1] = fill_sprite("images/fainted_dragon.png", 600, 300);
    spr[2] = fill_sprite("images/victory_scene.png", 0, 0);
    return (spr);
}