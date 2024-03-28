/*
** EPITECH PROJECT, 2021
** fill_text.c
** File description:
** RPG
*/

#include "header.h"

sfText *fill_text(char *title, int size, sfFont *font, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfText_setString(text, title);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    return text;
}