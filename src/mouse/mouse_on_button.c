/*
** EPITECH PROJECT, 2021
** mouse_on_button.c
** File description:
** RPG
*/

#include "header.h"

int mouse_on_button(mouse_t *m, button_t *btn)
{
    if (btn->spr->crds.x > m->x)
        return (0);
    if (btn->spr->crds.x + btn->spr->r.width < m->x)
        return (0);
    if (btn->spr->crds.y > m->y)
        return (0);
    if (btn->spr->crds.y + btn->spr->r.height < m->y)
        return (0);
    return (1);
}