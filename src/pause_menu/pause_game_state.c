/*
** EPITECH PROJECT, 2021
** pause_game_state.c
** File description:
** RPG
*/

#include "header.h"

void pause_game_state(game_t *game, int music_num)
{
    if (game->state == 10 || game->state == 3)
        game->state = 0;
    if (game->state == 11) {
        settings(game, music_num);
        pause_menu(game, music_num);
    }
    if (game->state == 12)
        game->state = -3;
    if (game->state == 13)
        game->state = 1;
}