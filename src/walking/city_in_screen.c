/*
** EPITECH PROJECT, 2021
** city_in_screen.c
** File description:
** RPG
*/

#include "header.h"

void city_in_screen(player_t *p, int mv)
{
    if (p->dir.y < 200 && p->dir.x > 700) {
        if (mv == 1)
            p->dir.y = 200;
        else
            p->dir.x = 700;
    }
    if (p->dir.y > 410 && p->dir.x < 280) {
        if (mv == 4)
            p->dir.y = 410;
        else
            p->dir.x = 280;
    }
    if (p->dir.x + 2 * p->dir.y < 330) {
        if (mv == 1)
            p->dir.y = (330 - p->dir.x) / 2;
        else
            p->dir.x = 330 - 2 * p->dir.y;
    }
}