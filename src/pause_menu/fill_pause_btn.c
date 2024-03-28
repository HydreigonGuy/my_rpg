/*
** EPITECH PROJECT, 2021
** fill_pause_btn.c
** File description:
** RPG
*/

#include "header.h"

button_t **fill_pause_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 4);
    for (int i = 0; i < 4; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->state = 0;
    }
    btn[0]->spr = fill_sprite("images/Resume.png", 500, 125);
    fill_rect(btn[0]->spr, 200, 100);
    btn[1]->spr = fill_sprite("images/settings_btn.png", 500, 250);
    fill_rect(btn[1]->spr, 200, 100);
    btn[2]->spr = fill_sprite("images/exit.png", 500, 500);
    fill_rect(btn[2]->spr, 200, 100);
    btn[3]->spr = fill_sprite("images/back_to_start.png", 500, 375);
    fill_rect(btn[3]->spr, 200, 100);
    return (btn);
}