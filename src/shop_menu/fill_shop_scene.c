/*
** EPITECH PROJECT, 2021
** fill_shop_scene.c
** File description:
** RPG
*/

#include "header.h"

static void fill_shop_buttons(scene_t *ret)
{
    int x  = 0;

    ret->btn[0]->spr = fill_sprite("images/shop_btn1.png", 900, 150);
    ret->btn[1]->spr = fill_sprite("images/shop_btn2.png", 900, 250);
    ret->btn[2]->spr = fill_sprite("images/shop_btn3.png", 900, 350);
    ret->btn[3]->spr = fill_sprite("images/shop_btn4.png", 900, 450);
    ret->btn[4]->spr = fill_sprite("images/shop_btn5.png", 900, 550);
    fill_rect(ret->btn[0]->spr, 200, 75);
    fill_rect(ret->btn[1]->spr, 200, 75);
    fill_rect(ret->btn[2]->spr, 200, 75);
    fill_rect(ret->btn[3]->spr, 200, 75);
    fill_rect(ret->btn[4]->spr, 200, 75);
    for (int i = 0; i < 6; i++) {
        x = 60 + i * 100;
        ret->btn[5 + i * 2]->spr = fill_sprite("images/sell_one.png", 300, x);
        ret->btn[6 + i * 2]->spr = fill_sprite("images/sell_all.png", 360, x);
        fill_rect(ret->btn[5 + i * 2]->spr, 50, 80);
        fill_rect(ret->btn[6 + i * 2]->spr, 50, 80);
    }
}

scene_t *fill_shop_scene(void)
{
    scene_t *ret = NULL;

    ret = malloc(sizeof(scene_t));
    ret->spr = malloc(sizeof(sprite_t) * 2);
    ret->spr[0] = fill_sprite("images/shop_menu.png", 600, 0);
    ret->spr[1] = fill_sprite("images/sells.png", 100, 50);
    ret->btn = malloc(sizeof(button_t) * 17);
    for (int i = 0; i < 17; i++) {
        ret->btn[i] = malloc(sizeof(button_t));
        ret->btn[i]->state = 0;
    }
    fill_shop_buttons(ret);
    return (ret);
}