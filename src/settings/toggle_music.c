/*
** EPITECH PROJECT, 2021
** toggle_music.c
** File description:
** RPG
*/

#include "header.h"

void play_music(music_t *music, int num)
{
    if (num == 1)
        sfMusic_play(music->city_theme);
    if (num == 2)
        sfMusic_play(music->lair_theme);
    if (num == 3)
        sfMusic_play(music->forest_theme);
    if (num == 4)
        sfMusic_play(music->cave_theme);
}

void stop_music(music_t *music, int num)
{
    if (num == 1)
        sfMusic_stop(music->city_theme);
    if (num == 2)
        sfMusic_stop(music->lair_theme);
    if (num == 3)
        sfMusic_stop(music->forest_theme);
    if (num == 4)
        sfMusic_stop(music->cave_theme);
}

void toggle_music(game_t *game, int music_num)
{
    if (game->music->is_playing == 1) {
        game->music->is_playing = 0;
        stop_music(game->music, music_num);
    } else {
        game->music->is_playing = 1;
        play_music(game->music, music_num);
    }
}