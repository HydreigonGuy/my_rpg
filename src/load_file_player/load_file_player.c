/*
** EPITECH PROJECT, 2021
** load_file_player.c
** File description:
** RPG
*/

#include "header.h"

char *read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char *text = NULL;
    struct stat buf;

    if (fd == -1)
        return (NULL);
    if (stat(file, &buf) == -1)
        return (NULL);
    text = malloc(sizeof(char) * (buf.st_size + 1));
    if (!text)
        return (NULL);
    if (read(fd, text, buf.st_size) == -1) {
        free(text);
        return (NULL);
    }
    text[buf.st_size] = '\0';
    close(fd);
    return (text);
}

player_t *load_file_player(char *file)
{
    char *stats = read_file(file);
    player_t *player = NULL;

    if (!stats || check_if_file_is_valid(stats))
        return (NULL);
    player = malloc(sizeof(player_t));
    player->spr = fill_sprite("images/player.png", 500, 300);
    fill_rect(player->spr, 100, 150);
    player->gold = get_player_stat(stats, 0);
    player->hp = get_player_stat(stats, 1);
    player->max_hp = get_player_stat(stats, 2);
    player->atk = get_player_stat(stats, 3);
    player->spd = get_player_stat(stats, 4);
    player->dir.x = 500;
    player->dir.y = 300;
    player->level = get_player_stat(stats, 5);
    player->xp = get_player_stat(stats, 6);
    player->quests = load_quests(stats);
    free(stats);
    return (player);
}