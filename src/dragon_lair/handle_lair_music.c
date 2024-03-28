/*
** EPITECH PROJECT, 2021
** handle_lair_music.c
** File description:
** RPG
*/

#include "header.h"

void handle_lair_music(music_t *music)
{
    if (music->is_playing) {
        sfMusic_play(music->lair_theme);
        sfMusic_setVolume(music->lair_theme, music->volume);
        sfMusic_setLoop(music->lair_theme, sfTrue);
    }
}