/*
** EPITECH PROJECT, 2021
** handle_forest_music.c
** File description:
** RPG
*/

#include "header.h"

void handle_forest_music(music_t *music)
{
    if (music->is_playing) {
        sfMusic_play(music->forest_theme);
        sfMusic_setVolume(music->forest_theme, music->volume);
        sfMusic_setLoop(music->forest_theme, sfTrue);
    }
}