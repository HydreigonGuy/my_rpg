/*
** EPITECH PROJECT, 2021
** free_sound.c
** File description:
** RPG
*/

#include "header.h"

void free_sound(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buff);
    free(sound);
}