/*
** EPITECH PROJECT, 2021
** fill_travel_btn.c
** File description:
** RPG
*/

#include "header.h"

button_t **fill_travel_btn(void)
{
    button_t **btn = NULL;

    btn = malloc(sizeof(button_t *) * 4);
    for (int i = 0; i < 4; i++) {
        btn[i] = malloc(sizeof(button_t));
        btn[i]->state = 0;
    }
    btn[0]->spr = fill_sprite("images/Forest_of_trees.png", 75, 200);
    fill_rect(btn[0]->spr, 200, 75);
    btn[1]->spr = fill_sprite("images/misterious_cave.png", 75, 300);
    fill_rect(btn[1]->spr, 200, 75);
    btn[2]->spr = fill_sprite("images/go_to_city.png", 75, 400);
    fill_rect(btn[2]->spr, 200, 75);
    btn[3]->spr = fill_sprite("images/dragon_lair.png", 75, 500);
    fill_rect(btn[3]->spr, 200, 75);
    return (btn);
}