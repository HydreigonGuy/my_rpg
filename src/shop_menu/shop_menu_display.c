/*
** EPITECH PROJECT, 2021
** shop_menu_display.c
** File description:
** RPG
*/

#include "header.h"

static void display_shop_btn(sprite_t *spr, game_t *g)
{
    sfSprite_setTextureRect(spr->spr, spr->r);
    sfRenderWindow_drawSprite(g->window, spr->spr, NULL);
}

void shop_menu_display(scene_t *shop, sprite_t *bg, game_t *g, number_t *qtts)
{
    bag_t *hold = g->bag->next;
    number_t *nbr = qtts;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    sfRenderWindow_drawSprite(g->window, shop->spr[0]->spr, NULL);
    sfRenderWindow_drawSprite(g->window, shop->spr[1]->spr, NULL);
    for (int i = 0; i < 5; i++)
        display_shop_btn(shop->btn[i]->spr, g);
    for (int i = 0; hold && i < 6; i++, hold = hold->next) {
        sfRenderWindow_drawSprite(g->window, hold->spr->spr, NULL);
        display_shop_btn(shop->btn[i * 2 + 5]->spr, g);
        display_shop_btn(shop->btn[i  *2 + 6]->spr, g);
    }
    for (; nbr; nbr = nbr->next)
        sfRenderWindow_drawSprite(g->window, nbr->spr->spr, NULL);
    sfRenderWindow_display(g->window);
}