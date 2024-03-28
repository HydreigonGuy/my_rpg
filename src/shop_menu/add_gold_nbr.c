/*
** EPITECH PROJECT, 2021
** add_gold_nbr.c
** File description:
** RPG
*/

#include "header.h"

number_t *fill_next_gold_num(int qtt, int x, int y)
{
    number_t *nbr = NULL;
    number_t *hold = NULL;

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

void add_gold_nbr(number_t **nums, int qtt, int x, int y)
{
    number_t *hold = *nums;

    if (!*nums) {
        *nums = fill_next_gold_num(qtt, x, y);
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_next_gold_num(qtt, x, y);
    }
}