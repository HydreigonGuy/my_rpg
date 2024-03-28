/*
** EPITECH PROJECT, 2021
** forest_display.c
** File description:
** RPG
*/

#include "header.h"

int check_is_tree_behind(sprite_t *tree, sprite_t *plr)
{
    int p = plr->crds.y + 150;
    int t = tree->crds.y;

    t = t + 180 + (t * 180) / 300;
    if (t < p)
        return (1);
    return (0);
}

void forest_display(forest_t *f, game_t *g)
{
    tree_t *h = f->tree;
    particle_t *hold2 = f->particle;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, f->forest[0]->spr, NULL);
    if (forest_can_interact(g->player->spr))
        sfRenderWindow_drawSprite(g->window, f->forest[1]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, f->forest[2]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, f->forest[3]->spr, NULL);
    sfSprite_setTextureRect(g->player->spr->spr, g->player->spr->r);
    sfRenderWindow_drawSprite(g->window, g->player->spr->spr, NULL);
    for (; h && check_is_tree_behind(h->spr, g->player->spr); h = h->next)
        sfRenderWindow_drawSprite(g->window, h->spr->spr, NULL);
    sfSprite_setTextureRect(g->player->spr->spr, g->player->spr->r);
    sfRenderWindow_drawSprite(g->window, g->player->spr->spr, NULL);
    for (; h; h = h->next)
        sfRenderWindow_drawSprite(g->window, h->spr->spr, NULL);
    for (; hold2; hold2 = hold2->next)
        sfRenderWindow_drawSprite(g->window, hold2->spr->spr, NULL);
    sfRenderWindow_display(g->window);
}