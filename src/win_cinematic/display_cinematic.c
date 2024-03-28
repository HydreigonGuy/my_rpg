/*
** EPITECH PROJECT, 2021
** display_cinematic.c
** File description:
** RPG
*/

#include "header.h"

void display_cinematic(game_t *g, sprite_t **spr)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (spr[0]->crds.x < -400) {
        sfRenderWindow_drawSprite(g->window, spr[2]->spr, NULL);
    } else {
        sfRenderWindow_drawSprite(g->window, spr[0]->spr, NULL);
        sfRenderWindow_drawSprite(g->window, spr[1]->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}