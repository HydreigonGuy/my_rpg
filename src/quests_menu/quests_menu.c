/*
** EPITECH PROJECT, 2021
** quests_menu.c
** File description:
** RPG
*/

#include "header.h"

void quests_menu(game_t *game, sprite_t *bg)
{
    button_t **btn = fill_quests();
    sprite_t *board = fill_sprite("images/quests_menu.png", 0, 0);

    mouse_reset(game->mouse);
    game->state = 0;
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        event_check(game);
        if (game->state != 3)
            mouse_check(btn, game, 3);
        qst_mnu_display(btn, bg, board, game);
        if (game->state >= 10 && game->state <= 15)
            game->state = 0;
    }
    game->state = 0;
}