/*
** EPITECH PROJECT, 2021
** mouse_check.c
** File description:
** RPG
*/

#include "header.h"

void mouse_check(button_t **btn, game_t *game, int c)
{
    for (int i = 0; i < c; i++) {
        btn[i]->state = 0;
        if (mouse_on_button(game->mouse, btn[i]))
            btn[i]->state = 1;
        if (mouse_pressed_button(game->mouse, btn[i]))
            btn[i]->state = 2;
        if (mouse_released_on_button(game->mouse, btn[i]))
            game->state = 10 + i;
        btn[i]->spr->r.left = btn[i]->state * btn[i]->spr->r.width;
    }
}