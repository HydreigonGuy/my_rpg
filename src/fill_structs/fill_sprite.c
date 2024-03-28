/*
** EPITECH PROJECT, 2021
** fill_sprite.c
** File description:
** RPG
*/

#include "header.h"

sprite_t *fill_sprite(char *file, int setx, int sety)
{
    sprite_t *sp;

    sp = malloc(sizeof(sprite_t));
    sp->txtr = sfTexture_createFromFile(file, NULL);
    sp->spr = sfSprite_create();
    sfSprite_setTexture(sp->spr, sp->txtr, sfTrue);
    sp->crds.x = setx;
    sp->crds.y = sety;
    sfSprite_setPosition(sp->spr, sp->crds);
    return (sp);
}