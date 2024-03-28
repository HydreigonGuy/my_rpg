/*
** EPITECH PROJECT, 2021
** fill_bag_scene.c
** File description:
** RPG
*/

#include "header.h"

bag_scene_t *fill_bag_scene(game_t *g)
{
    bag_scene_t *ret = NULL;

    ret = malloc(sizeof(bag_scene_t));
    ret->board = fill_sprite("images/inventory.png", 300, 150);
    ret->btn = malloc(sizeof(button_t *));
    ret->btn[0] = malloc(sizeof(button_t));
    ret->btn[0]->spr = fill_sprite("images/use.png", 320, 420);
    fill_rect(ret->btn[0]->spr, 40, 20);
    ret->select = 0;
    ret->display_use = 0;
    return (ret);
}