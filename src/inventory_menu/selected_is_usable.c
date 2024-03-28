/*
** EPITECH PROJECT, 2021
** selected_is_usable.c
** File description:
** RPG
*/

#include "header.h"

int selected_is_usable(int id)
{
    if (id == 1 || id == 2)
        return (1);
    return (0);
}