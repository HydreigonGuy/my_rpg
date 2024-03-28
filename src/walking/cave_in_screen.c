/*
** EPITECH PROJECT, 2021
** cave_in_screen.c
** File description:
** RPG
*/

#include "header.h"

void cave_in_screen(player_t *p, int mv)
{
    if (p->dir.y > 410 && p->dir.x < 280) {
        if (mv == 4)
            p->dir.y = 410;
        else
            p->dir.x = 280;
    }
    if (p->dir.y < 130)
        p->dir.y = 130;
    if (p->dir.x > 800 && p->dir.y < 200) {
        if (mv == 1)
            p->dir.y = 200;
        else
            p->dir.x = 800;
    }
    if (p->dir.x > 950 && p->dir.y < 300) {
        if (mv == 1)
            p->dir.y = 300;
        else
            p->dir.x = 950;
    }
}