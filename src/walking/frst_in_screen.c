/*
** EPITECH PROJECT, 2021
** frst_in_screen.c
** File description:
** RPG
*/

#include "header.h"

void frst_in_screen(player_t *p, int mv)
{
    if (p->dir.y > 410 && p->dir.x < 280) {
        if (mv == 4)
            p->dir.y = 410;
        else
            p->dir.x = 280;
    }
}