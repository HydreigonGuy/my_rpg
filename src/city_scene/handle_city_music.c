/*
** EPITECH PROJECT, 2021
** handle_city_music.c
** File description:
** RPG
*/

#include "header.h"

void handle_city_music(music_t *music)
{
    if (music->is_playing) {
        sfMusic_play(music->city_theme);
        sfMusic_setVolume(music->city_theme, music->volume);
        sfMusic_setLoop(music->city_theme, sfTrue);
    }
}