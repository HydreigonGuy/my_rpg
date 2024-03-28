/*
** EPITECH PROJECT, 2021
** fill_toturial.c
** File description:
** RPG
*/

#include "header.h"

sprite_t **fill_toturial(void)
{
    sprite_t **ret = NULL;

    ret = malloc(sizeof(sprite_t *) * 2);
    ret[0] = fill_sprite("images/tutorial1.png", 0, 0);
    ret[1] = fill_sprite("images/tutorial2.png", 0, 0);
    return (ret);
}