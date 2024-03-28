/*
** EPITECH PROJECT, 2021
** shop_menu.c
** File description:
** RPG
*/

#include "header.h"

void shop_menu(game_t *game, sprite_t *bg)
{
    scene_t *shop = fill_shop_scene();
    number_t *nbr = NULL;

    mouse_reset(game->mouse);
    game->state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        if (game->state != 3)
            mouse_check(shop->btn, game, 17);
        purchase_check(game);
        nbr = organise_shop_items(game);
        shop_menu_display(shop, bg, game, nbr);
    }
    free_shop_scene(shop);
    game->state = 0;
}