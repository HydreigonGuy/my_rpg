/*
** EPITECH PROJECT, 2021
** change_settings.c
** File description:
** RPG
*/

#include "header.h"

void change_settings(game_t *game, int music_num)
{
    if (game->state == 10)
        game->state = 3;
    if (game->state && game->state != 3) {
        if (game->state == 11)
            toggle_music(game, music_num);
        if (game->state == 12)
            change_volume(game->music, -5, music_num);
        if (game->state == 13)
            change_volume(game->music, 5, music_num);
        game->state = 0;
        mouse_reset(game->mouse);
    }
}