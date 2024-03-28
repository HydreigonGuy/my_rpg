/*
** EPITECH PROJECT, 2021
** fill_bag.c
** File description:
** RPG
*/

#include "header.h"

bag_t *fill_bag(void)
{
    bag_t *ret = NULL;

    ret = malloc(sizeof(bag_t));
    ret->id = 0;
    ret->quantity = 0;
    ret->spr = NULL;
    ret->next = NULL;
    return (ret);
}