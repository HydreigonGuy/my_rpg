/*
** EPITECH PROJECT, 2021
** fill_quests.c
** File description:
** RPG
*/

#include "header.h"

button_t **fill_quests(void)
{
    button_t **quests = NULL;

    quests = malloc(sizeof(button_t *) * 3);
    for (int i = 0; i < 3; i++) {
        quests[i] = malloc(sizeof(button_t));
        quests[i]->state = 0;
    }
    quests[0]->spr = fill_sprite("images/quest1.png", 75, 200);
    fill_rect(quests[0]->spr, 200, 75);
    quests[1]->spr = fill_sprite("images/quest2.png", 75, 300);
    fill_rect(quests[1]->spr, 200, 75);
    quests[2]->spr = fill_sprite("images/quest3.png", 75, 400);
    fill_rect(quests[2]->spr, 200, 75);
    return (quests);
}