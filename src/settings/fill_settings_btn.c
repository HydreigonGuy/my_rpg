/*
** EPITECH PROJECT, 2021
** fill_settings_btn.c
** File description:
** RPG
*/

#include "header.h"

button_t **fill_settings_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 4);
    for (int i = 0; i < 4; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->state = 0;
    }
    btn[0]->spr = fill_sprite("images/exit.png", 500, 500);
    btn[1]->spr = fill_sprite("images/toggle_music.png", 500, 100);
    btn[2]->spr = fill_sprite("images/volume_down.png", 250, 300);
    btn[3]->spr = fill_sprite("images/volume_up.png", 750, 300);
    fill_rect(btn[0]->spr, 200, 100);
    fill_rect(btn[1]->spr, 200, 100);
    fill_rect(btn[2]->spr, 200, 100);
    fill_rect(btn[3]->spr, 200, 100);
    return (btn);
}