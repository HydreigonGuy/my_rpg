/*
** EPITECH PROJECT, 2021
** how_to_play.c
** File description:
** RPG
*/

#include "header.h"

void how_to_play(game_t *game)
{
    sprite_t **bg = fill_toturial();
    int tutorial_spot = 0;

    mouse_reset(game->mouse);
    game->state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        if (game->key == 7)
            tutorial_spot++;
        if (tutorial_spot > 1 || game->key == 6)
            game->state = 1;
        if (game->state == 0)
            tuto_menu_display(bg, game, tutorial_spot);
    }
    for (int i = 0; i < 2; i++)
        free_sprite(bg[i]);
}