/*
** EPITECH PROJECT, 2021
** get_item_spr.c
** File description:
** RPG
*/

#include "header.h"

char *get_item_spr(int id)
{
    if (id == 1)
        return ("images/potion.png");
    if (id == 2)
        return ("images/sandwitch.png");
    if (id == 11)
        return ("images/dagger.png");
    if (id == 12)
        return ("images/spear.png");
    if (id == 13)
        return ("images/axe.png");
    if (id == 21)
        return ("images/wood.png");
    if (id == 22)
        return ("images/leef.png");
    if (id == 23)
        return ("images/furr.png");
    if (id == 24)
        return ("images/tooth.png");
    if (id == 26)
        return ("images/pouch.png");
}