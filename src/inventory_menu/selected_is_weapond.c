/*
** EPITECH PROJECT, 2021
** selected_is_weapond.c
** File description:
** RPG
*/

#include "header.h"

int selected_is_weapond(int id)
{
    if (id == 11 || id == 12 || id == 13)
        return (1);
    return (0);
}