/*
** EPITECH PROJECT, 2021
** inventory_menu.c
** File description:
** RPG
*/

#include "header.h"

void inventory_menu(game_t *game, sprite_t *bg)
{
    bag_scene_t *inv = fill_bag_scene(game);

    mouse_reset(game->mouse);
    game->state = 0;
    inv->nbr = organise_inventory_items(game);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        if (game->state != 3) {
            mouse_check(inv->btn, game, 1);
            item_select_check(game, inv);
        }
        inventory_display(bg, inv, game);
        if (game->state >= 10 && game->state <= 15)
            game->state = 0;
    }
    free_bag_scene(inv);
    game->state = 0;
}