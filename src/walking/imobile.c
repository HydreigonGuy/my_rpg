/*
** EPITECH PROJECT, 2021
** imobile.c
** File description:
** RPG
*/

#include "header.h"

int imobile(player_t *p)
{
    if (p->dir.x != p->spr->crds.x)
        return (0);
    if (p->dir.y != p->spr->crds.y)
        return (0);
    return (1);
}