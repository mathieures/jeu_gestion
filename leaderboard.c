#include "leaderboard.h"

leaderboard create_player(char name[21], int score)
{
    leaderboard result;
    result = (player*)calloc(1, sizeof(player));

    strcpy(result->name, name); // dest, src
    result->score = score;
    result->svt = NULL;

    return result;
}

/*
void print_player(player* pplayer)
{
    printf("  nom : %s\n", pplayer->name);
    printf("  score : %d\n", pplayer->score);
}
*/

leaderboard get_player_by_name(leaderboard lb, char name[21])
{
    leaderboard tmp;
    // tmp = lb;
    for (tmp = lb; tmp; tmp = tmp->svt)
    // while (tmp)
    {
        if (0 == strcmp(tmp->name, name))
            break;
        // tmp = tmp->svt;
    }
    return tmp;
}


leaderboard read_leaderboard(char filename[])
{
    FILE* lb_file;
    lb_file = fopen(filename, "r"); // retourne NULL s'il n'existe pas
    if (!lb_file)
        lb_file = fopen(filename, "w+");

    leaderboard result = NULL;

    // lignes de la forme : 20 caractères, une espace, et un nombre
    char temp_name[21];
    int temp_score;
    while (EOF != fscanf(lb_file, "%s %d", temp_name, &temp_score))
        add_player_to_leaderboard(&result, temp_name, temp_score);
    fclose(lb_file);
    return result;
}

void write_leaderboard(leaderboard lb, char filename[])
{
    FILE* lb_file;
    lb_file = fopen(filename, "w"); // retourne NULL s'il n'existe pas

    // lignes de la forme : 20 caractères, une espace, et un nombre
    leaderboard tmp;
    // tmp = lb;
    for (tmp = lb; tmp; tmp = tmp->svt)
    // while (tmp)
    // {
        fprintf(lb_file, "%s %d\n", tmp->name, tmp->score);
        // tmp = tmp->svt;
    // }
    fclose(lb_file);
}


void print_leaderboard(leaderboard lb)
{
    int i = 1;
    leaderboard tmp;
    // tmp = lb;
    printf("LEADERBOARD :\n");
    for (tmp = lb; tmp; tmp = tmp->svt)
    // while (tmp)
    // {
        printf("%i - %s : %d pt(s)\n", i++, tmp->name, tmp->score);
        // tmp = tmp->svt;
    // }
    printf("------------\n");
}


void add_player_to_leaderboard(leaderboard* lb, char name[21], int score)
{
    player *new_player, *prec, *tmp;
    /*
    // On détermine si le joueur existe déjà
    new_player = get_player_by_name((*lb), name);
    if (!new_player)
        new_player = create_player(name, score);
    else if (new_player->score < score)
        new_player->score = score;
    */
    
    new_player = create_player(name, score);
    // On insère le nouveau à la bonne place directement
    tmp = (*lb);

    // Si le leaderboard est vide ou que le premier score est inférieur au nouveau
    if (!tmp || tmp->score < score)
    {
        new_player->svt = tmp;
        (*lb) = new_player;
    }
    else
    {
        prec = NULL;
        // Tant qu'il y a qqch après et que le score du suivant est supérieur, on continue
        for (tmp = (*lb); tmp && tmp->score >= score; tmp = tmp->svt)
        // while (tmp && tmp->score >= score)
        // {
            prec = tmp;
            // tmp = tmp->svt;
        // }
        // On a donc la bonne position
        new_player->svt = tmp;
        prec->svt = new_player;
    }
}

void remove_player_from_leaderboard(leaderboard lb, player* pplayer)
{
    player* tmp;
    // tmp = lb;
    for (tmp = lb; tmp; tmp = tmp->svt)
    // while (tmp)
    {
        // Si le prochain a le meme nom
        if (0 == strcmp(tmp->svt->name, pplayer->name))
        {
            tmp->svt = pplayer->svt;
            free(pplayer);
            break;
        }
        // tmp = tmp->svt;
    }
}


void free_leaderboard(leaderboard lb)
{
    leaderboard tmp;
    while (lb)
    {
        tmp = lb->svt;
        free(lb);
        lb = tmp;
    }
}