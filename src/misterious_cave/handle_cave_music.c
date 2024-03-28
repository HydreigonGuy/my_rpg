/*
** EPITECH PROJECT, 2021
** handle_cave_music.c
** File description:
** RPG
*/

#include "header.h"

void handle_cave_music(music_t *music)
{
    if (music->is_playing) {
        sfMusic_play(music->cave_theme);
        sfMusic_setVolume(music->cave_theme, music->volume);
        sfMusic_setLoop(music->cave_theme, sfTrue);
    }
}