/*
** EPITECH PROJECT, 2021
** start_menu.c
** File description:
** RPG
*/

#include "header.h"

void start_menu(game_t *game)
{
    sprite_t *start_bg = fill_sprite("images/start_bg.png", 0, 0);
    button_t **btn = fill_start_btn();

    mouse_reset(game->mouse);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        mouse_check(btn, game, 4);
        start_display(start_bg, btn, game);
    }
    for (int i = 0; i < 4; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    free_sprite(start_bg);
    start_menu_game_state_set(game);
}