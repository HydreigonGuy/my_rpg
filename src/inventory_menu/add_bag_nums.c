/*
** EPITECH PROJECT, 2021
** add_bag_nums.c
** File description:
** RPG
*/

#include "header.h"

void add_one_bag_num(number_t *nbr, int x, int y, int n)
{
    nbr->spr = fill_sprite("images/numbers.png", x, y);
    fill_rect(nbr->spr, 10, 10);
    nbr->spr->r.left = 10 * n;
    sfSprite_setTextureRect(nbr->spr->spr, nbr->spr->r);
    nbr->next = NULL;
}

number_t *fill_next_bag_num(int qtt, int spot)
{
    int x = 365 + (spot % 6) * 100;
    int y = 225 + (spot / 6) * 100;
    number_t *nbr = NULL;
    number_t *hold = NULL;

    if (spot == -1) {
        x = 830;
        y = 520;
    }
    nbr = malloc(sizeof(number_t));
    add_one_bag_num(nbr, x, y, qtt % 10);
    hold = nbr;
    for (int i = 10; i <= qtt; i = i * 10, hold = hold->next) {
        hold->next = malloc(sizeof(number_t));
        x = x - 10;
        add_one_bag_num(hold->next, x, y, (qtt / i) % 10);
    }
    hold->next = malloc(sizeof(number_t));
    add_one_bag_num(hold->next, x - 10, y, 10);
    return (nbr);
}

void add_bag_nums(number_t **nums, int qtt, int spot)
{
    number_t *hold = *nums;

    if (!*nums) {
        *nums = fill_next_bag_num(qtt, spot);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_next_bag_num(qtt, spot);
    }
}