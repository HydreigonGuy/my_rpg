/*
** EPITECH PROJECT, 2021
** tuto_menu_display.c
** File description:
** RPG
*/

#include "header.h"

void tuto_menu_display(sprite_t **bg, game_t *g, int spot)
{
    sfRenderWindow_clear(g->window, sfBlack);
    if (bg[spot])
        sfRenderWindow_drawSprite(g->window, bg[spot]->spr, NULL);
    sfRenderWindow_display(g->window);
}