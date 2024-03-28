/*
** EPITECH PROJECT, 2021
** quests_menu_display.c
** File description:
** RPG
*/

#include "header.h"

int quest_complete(int progress, int num)
{
    if (num == 0 && progress >= 20)
        return (1);
    if (num == 1 && progress >= 20)
        return (1);
    if (num == 2 && progress)
        return (1);
    return (0);
}

void rerect_quest(sprite_t *spr, int *quests, int i)
{
    if (spr->r.left == 2 * spr->r.width)
        spr->r.left = spr->r.width;
    if (quest_complete(quests[i], i)) {
        if (spr->r.left == 0)
            spr->r.left = 2 * spr->r.width;
    }
}

void qst_mnu_display(button_t **btn, sprite_t *bg, sprite_t *brd, game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, bg->spr, NULL);
    sfRenderWindow_drawSprite(g->window, brd->spr, NULL);
    for (int i = 0; i < 3; i++) {
        rerect_quest(btn[i]->spr, g->player->quests, i);
        sfSprite_setTextureRect(btn[i]->spr->spr, btn[i]->spr->r);
        sfRenderWindow_drawSprite(g->window, btn[i]->spr->spr, NULL);
    }
    sfRenderWindow_display(g->window);
}