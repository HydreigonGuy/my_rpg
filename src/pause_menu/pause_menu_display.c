/*
** EPITECH PROJECT, 2021
** pause_menu_diplay.c
** File description:
** RPG
*/

#include "header.h"

void pause_menu_display(button_t **btn, sprite_t *bg, game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    for (int i = 0; i < 4; i++) {
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}