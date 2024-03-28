/*
** EPITECH PROJECT, 2021
** mouse_reset.c
** File description:
** RPG
*/

#include "header.h"

void mouse_reset(mouse_t *mouse)
{
    mouse->x = 0;
    mouse->y = 0;
    mouse->p_x = 0;
    mouse->p_y = 0;
    mouse->r_x = 0;
    mouse->r_y = 0;
}