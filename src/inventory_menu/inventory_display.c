/*
** EPITECH PROJECT, 2021
** inventory_display.c
** File description:
** RPG
*/

#include "header.h"

void inventory_display(sprite_t *bg, bag_scene_t *inv, game_t *g)
{
    bag_t *hold = g->bag;
    number_t *nbr = inv->nbr;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    sfRenderWindow_drawSprite(g->window, inv->board->spr, NULL);
    for (; hold; hold = hold->next)
        if (hold->spr)
            sfRenderWindow_drawSprite(g->window, hold->spr->spr, NULL);
    for (; nbr; nbr = nbr->next)
        sfRenderWindow_drawSprite(g->window, nbr->spr->spr, NULL);
    if (inv->display_use) {
        sfSprite_setTextureRect(inv->btn[0]->spr->spr, inv->btn[0]->spr->r);
        sfRenderWindow_drawSprite(g->window, inv->btn[0]->spr->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}