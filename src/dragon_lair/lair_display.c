/*
** EPITECH PROJECT, 2021
** lair_display.c
** File description:
** RPG
*/

#include "header.h"

void lair_display(lair_t *lair, game_t *g)
{
    attack_t *hold = lair->atk;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, lair->bg->spr, NULL);
    if (lair->dragon) {
        sfRenderWindow_drawSprite(g->window, lair->dragon->spr, NULL);
        sfRenderWindow_drawSprite(g->window, lair->health_bar->spr, NULL);
    }
    sfSprite_setTextureRect(g->player->spr->spr, g->player->spr->r);
    sfRenderWindow_drawSprite(g->window, g->player->spr->spr, NULL);
    for (; hold; hold = hold->next)
        sfRenderWindow_drawSprite(g->window, hold->spr->spr, NULL);
    if (forest_can_interact(g->player->spr))
        sfRenderWindow_drawSprite(g->window, lair->spr[0]->spr, NULL);
    for (int i = 1; i < 7; i++)
        sfRenderWindow_drawSprite(g->window, lair->spr[i]->spr, NULL);
    sfRenderWindow_display(g->window);
}