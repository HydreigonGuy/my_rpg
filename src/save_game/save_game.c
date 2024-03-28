/*
** EPITECH PROJECT, 2021
** save_game.c
** File description:
** RPG
*/

#include "header.h"

void save_game(game_t *g)
{
    int fd = open();

    if (fd == -1)
        write(1, "Error Saving: could not open text file\n", 39);
    else {
        write(fd, "gold = ");
        write(fd, "\nhp = ");
        write(fd, "\nmax_hp = ");
        write(fd, "\natk = ");
        write(fd, "\nspd = ");
        write(fd, "\nlevel = ");
        write(fd, "\nxp = ");
        write(fd, "\nquest_one = ");
        write(fd, "\nquest_two = ");
        write(fd, "\nquest_three = ");
    }
}