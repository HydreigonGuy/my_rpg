/*
** EPITECH PROJECT, 2021
** travel_menu.c
** File description:
** RPG
*/

#include "header.h"

void travel_menu(game_t *game, sprite_t *bg)
{
    button_t **btn = fill_travel_btn();
    sprite_t *board = fill_sprite("images/travel_menu.png", 0, 0);

    mouse_reset(game->mouse);
    game->state = 0;
    sfSound_play(game->music->sound[2]->sound);
    sfSound_setVolume(game->music->sound[2]->sound, game->music->volume);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        mouse_check(btn, game, 4);
        trvl_menu_display(btn, bg, board, game);
    }
    travel_menu_state_set(game);
}