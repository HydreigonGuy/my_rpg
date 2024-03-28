/*
** EPITECH PROJECT, 2021
** change_volume.c
** File description:
** RPG
*/

#include "header.h"

void set_new_volume(music_t *music, int num)
{
    if (num == 1)
        sfMusic_setVolume(music->city_theme, music->volume);
    if (num == 2)
        sfMusic_setVolume(music->lair_theme, music->volume);
    if (num == 3)
        sfMusic_setVolume(music->forest_theme, music->volume);
    if (num == 4)
        sfMusic_setVolume(music->cave_theme, music->volume);
}

void change_volume(music_t *music, int change, int music_num)
{
    music->volume += change;
    if (music->volume < 0)
        music->volume = 0;
    if (music->volume > 100)
        music->volume = 100;
    if (music->is_playing)
        set_new_volume(music, music_num);
}