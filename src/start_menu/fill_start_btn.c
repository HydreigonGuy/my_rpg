/*
** EPITECH PROJECT, 2021
** fill_start_btn.c
** File description:
** RPG
*/

#include "header.h"

button_t **fill_start_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 4);
    for (int i = 0; i < 4; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->state = 0;
    }
    btn[0]->spr = fill_sprite("images/play_btn.png", 400, 100);
    fill_rect(btn[0]->spr, 400, 200);
    btn[1]->spr = fill_sprite("images/settings_btn.png", 500, 450);
    fill_rect(btn[1]->spr, 200, 100);
    btn[2]->spr = fill_sprite("images/exit.png", 500, 575);
    fill_rect(btn[2]->spr, 200, 100);
    btn[3]->spr = fill_sprite("images/how_to_play.png", 500, 325);
    fill_rect(btn[3]->spr, 200, 100);
    return (btn);
}