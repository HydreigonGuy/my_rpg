/*
** EPITECH PROJECT, 2021
** fainting_display.c
** File description:
** RPG
*/

#include "header.h"

void fainting_display(sprite_t **spr, game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, spr[0]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, spr[1]->spr, NULL);
    sfRenderWindow_display(g->window);
}