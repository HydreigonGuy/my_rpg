/*
** EPITECH PROJECT, 2021
** fill_sound.c
** File description:
** RPG
*/

#include "header.h"

sound_t *fill_sound(char *file)
{
    sound_t *ret = NULL;

    ret = malloc(sizeof(sound_t));
    ret->sound = sfSound_create();
    ret->buff = sfSoundBuffer_createFromFile(file);
    sfSound_setBuffer(ret->sound, ret->buff);
    return (ret);
}