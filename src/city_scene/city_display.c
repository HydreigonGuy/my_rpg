/*
** EPITECH PROJECT, 2021
** city_display.c
** File description:
** RPG
*/

#include "header.h"

void city_display(scene_t *s, game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, s->spr[0]->spr, NULL);
    if (city_can_interact(g->player->spr))
        sfRenderWindow_drawSprite(g->window, s->spr[1]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, s->spr[2]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, s->spr[3]->spr, NULL);
    sfSprite_setTextureRect(g->player->spr->spr, g->player->spr->r);
    sfRenderWindow_drawSprite(g->window, g->player->spr->spr, NULL);
    sfRenderWindow_display(g->window);
}