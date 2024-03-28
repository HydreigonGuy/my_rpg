/*
** EPITECH PROJECT, 2021
** add_tree.c
** File description:
** RPG
*/

#include "header.h"

void sort_trees(tree_t *tree)
{
    tree_t *hold = tree;
    sprite_t *spr = NULL;

    for (; hold; hold = hold->next)
        if (hold->next && hold->next->spr->crds.y < hold->spr->crds.y) {
            spr = hold->next->spr;
            hold->next->spr = hold->spr;
            hold->spr = spr;
        }
}

void add_tree(tree_t **tree)
{
    tree_t *hold = *tree;

    if (!*tree) {
        *tree = fill_next_tree();
    } else {
        for (; hold && hold->next; hold = hold->next);
        hold->next = fill_next_tree();
    }
    hold = *tree;
    for (; hold; hold = hold->next)
        sort_trees(*tree);
}