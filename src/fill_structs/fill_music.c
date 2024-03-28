/*
** EPITECH PROJECT, 2021
** fill_music.c
** File description:
** RPG
*/

#include "header.h"

music_t *fill_music(void)
{
    music_t *music = NULL;

    music = malloc(sizeof(music_t));
    music->city_theme = sfMusic_createFromFile("music/city_theme.wav");
    music->lair_theme = sfMusic_createFromFile("music/lair_theme.wav");
    music->forest_theme = sfMusic_createFromFile("music/forest_theme.wav");
    music->cave_theme = sfMusic_createFromFile("music/cave_theme.wav");
    music->volume = 20;
    music->is_playing = 1;
    music->sound = malloc(sizeof(sound_t *) * 4);
    music->sound[0] = fill_sound("music/win.wav");
    music->sound[1] = fill_sound("music/level_up.wav");
    music->sound[2] = fill_sound("music/travel.wav");
    music->sound[3] = fill_sound("music/transaction.wav");
    return (music);
}