/*
** EPITECH PROJECT, 2021
** mouse_released_on_button.c
** File description:
** RPG
*/

#include "header.h"

int mouse_pressed_button(mouse_t *m, button_t *btn)
{
    if (btn->spr->crds.x > m->p_x)
        return (0);
    if (btn->spr->crds.x + btn->spr->r.width < m->p_x)
        return (0);
    if (btn->spr->crds.y > m->p_y)
        return (0);
    if (btn->spr->crds.y + btn->spr->r.height < m->p_y)
        return (0);
    return (1);
}

int mouse_released_on_button(mouse_t *m, button_t *btn)
{
    if (btn->spr->crds.x > m->r_x)
        return (0);
    if (btn->spr->crds.x + btn->spr->r.width < m->r_x)
        return (0);
    if (btn->spr->crds.y > m->r_y)
        return (0);
    if (btn->spr->crds.y + btn->spr->r.height < m->r_y)
        return (0);
    return (1);
}