#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _player_ {
    char name[20];
    int score;
    struct _player_* svt;
} player, *leaderboard; // liste chaînée de joueurs


leaderboard create_player(char name[20], int score);
// void print_player(player* pplayer);

leaderboard get_player_by_name(leaderboard lb, char name[20]);

// leaderboard init_lb(void);
leaderboard read_leaderboard(char filename[]);
void write_leaderboard(leaderboard lb, char filename[]);

void print_leaderboard(leaderboard lb);

void add_player_to_leaderboard(leaderboard* lb, char name[20], int score); // INSÉRER en triant du plus grand au plus petit score
int remove_player_from_leaderboard(leaderboard lb, player* pplayer); // retourne 0 si pas trouvé

void free_leaderboard(leaderboard lb);

/*
idée : dans le classement, mettre des timestamps, genre quand est-ce que tu as obtenu ce score
il faudrait un moyen de mettre un nom à côté peut-être ?
*/

#endif

