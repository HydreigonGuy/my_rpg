/*
** EPITECH PROJECT, 2021
** cave_display.c
** File description:
** RPG
*/

#include "header.h"

void cave_display(cave_t *s, game_t *g)
{
    enemy_t *hold = s->enemy;
    attack_t *hold2 = s->atks;
    particle_t *hold3 = s->particle;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, s->scene->spr[0]->spr, NULL);
    for (; hold3; hold3 = hold3->next)
        sfRenderWindow_drawSprite(g->window, hold3->spr->spr, NULL);
    if (cave_can_interact(g->player->spr))
        sfRenderWindow_drawSprite(g->window, s->scene->spr[1]->spr, NULL);
    for (int i = 2; i < 8; i++)
        sfRenderWindow_drawSprite(g->window, s->scene->spr[i]->spr, NULL);
    sfSprite_setTextureRect(g->player->spr->spr, g->player->spr->r);
    for (; hold; hold = hold->next)
        sfRenderWindow_drawSprite(g->window, hold->spr->spr, NULL);
    for (; hold2; hold2 = hold2->next)
        sfRenderWindow_drawSprite(g->window, hold2->spr->spr, NULL);
    sfRenderWindow_drawSprite(g->window, g->player->spr->spr, NULL);
    sfRenderWindow_display(g->window);
}