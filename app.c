// Peut-être pas necessaires
// #ifdef _WIN32
// #include <Windows.h>
// #else
// #include <unistd.h>
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "screen.h"
#include "rules.h"
#include "leaderboard.h"
#include "potager.h"
#include "plante.h"
#include "mygetch.h"

// Initialisation des variables

int paused = 0;
char key;
int taille_potager = 10;
int curseur_x = 0, curseur_y = 0;

int max_turns;
int score = 0;

void pause_game(void) { paused = 1; }

void resume_game(void) { paused = 0; }

void reverse_colors_in_potager_at(potager ppotager, int x, int y)
{
    if (in_potager(ppotager, x, y))
    {
        save_cursor_position();
        reverse_colors();
        move_cursor_in_potager_to(ppotager, x, y);
        print_plante_at(ppotager, x, y);
        reverse_colors();
        restore_cursor_position();
    }
}

int main(void)
{
    (void)srand(time(NULL));
    max_turns = taille_potager * 10;

    potager p;
    p = create_potager(taille_potager);

    leaderboard lb;
    lb = read_leaderboard("leaderboard.txt");

    clear_screen();
    move_cursor_to(0, 0);

    print_rules(max_turns);
    printf("\n");


    // Boucle de jeu
    print_potager(p);
    int i = 0;
    while (i < max_turns)
    {
        // printf("Appuyer sur une touche : ");
        key = mygetch();
        // Si ce n'est pas un caractere echappe
        if (key != 27)
        {
            // Jeu ici
            // printf("%c (ascii : %d)\n", key, key);
            switch (key)
            {
                case 'l':
                    clear_screen();
                    move_cursor_to(0, 0);
                    if (!paused)
                    {
                        pause_game();
                        print_leaderboard(lb);
                    }
                    else
                    {
                        resume_game();
                        print_rules(max_turns);
                        printf("\n");
                        print_potager(p);
                    }
                    break;
                case 'p':
                    if (!paused)
                        pause_game();
                    else
                        resume_game();
                    break;
                default:
                    if (!paused)
                    {
                        switch (key)
                        {
                            case 'q':
                                if (curseur_x > 0)
                                    curseur_x--;
                                break;
                            case 'd':
                                if (curseur_x < p.taille-1)
                                    curseur_x++;
                                break;
                            case 'z':
                                if (curseur_y > 0)
                                    curseur_y--;
                                break;
                            case 's':
                                if (curseur_y < p.taille-1)
                                    curseur_y++;
                                break;
                            case ' ':
                                score += cueillir(p, curseur_x, curseur_y); // la valeur de retour est l'âge
                                break;
                            default:
                                break;
                        }
                        faire_pousser_potager(p); // fait pousser a chaque appui de touche
                        move_cursor_in_potager_to(p, 0, 0);
                        print_potager(p);
                        reverse_colors_in_potager_at(p, curseur_x, curseur_y);
                        printf("Score : %d", score);
                        i++;
                    }
                    break;
            }
        }
        else
            break;
    }
    reset_colors();
    printf("\n");

    // Sauvegarder le leaderboard dans le fichier
    printf("Enregistrer score ? [O/N] : ");
    char answer[21];
    scanf("%s", answer);
    // Si la reponse est differente de 'n' (non)
    if (strcmp(answer, "n"))
    {
        printf("Nom du joueur a enregistrer : ");
        char name[21];
        int len;
        scanf("%s", name);
        len = strlen(name);
        if (2 <= len && len < 21)
        {
            player* already_here = get_player_by_name(lb, name);

            if (already_here && already_here->score < score)
            {
                remove_player_from_leaderboard(lb, already_here);
                add_player_to_leaderboard(&lb, name, score);
            }
        }
        else
            printf("Nom invalide : entrer un nom entre 2 et 20 caracteres\n");
    }

    print_leaderboard(lb);

    write_leaderboard(lb, "leaderboard.txt");
    free_leaderboard(lb);
    free_potager(&p);

    return 0;
}