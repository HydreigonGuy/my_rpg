/*
** EPITECH PROJECT, 2021
** pause_menu.c
** File description:
** RPG
*/

#include "header.h"

void pause_menu(game_t *game, int music_num)
{
    button_t **btn = fill_pause_btn();
    sprite_t *bg = fill_sprite("images/start_bg.png", 0, 0);

    mouse_reset(game->mouse);
    game->state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        mouse_check(btn, game, 4);
        pause_menu_display(btn, bg, game);
    }
    for (int i = 0; i < 4; i++) {
        free_sprite(btn[i]->spr);
        free(btn[i]);
    }
    pause_game_state(game, music_num);
    game->time = sfClock_getElapsedTime(game->clock);
}