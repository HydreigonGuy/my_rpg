/*
** EPITECH PROJECT, 2021
** s_case.c
** File description:
** RPG
*/

#include "header.h"

int s_case(void)
{
    write(1, "You can give a file as an argument to set your stats", 52);
    write(1, " for the game before you play it.\n", 35);
    write(1, "The file must be written like the following (replacing", 54);
    write(1, " the \"...\" by an integer) :\ngold = ...\nhp = ...\n", 48);
    write(1, "max_hp = ...\natk = ...\nspd = ...\nlevel = ...\n", 45);
    write(1, "xp = ...\nquest_one_status = ...\n", 32);
    write(1, "quest_two_status = ...\nquest_tree_status = ...\n", 47);
    return (0);
}