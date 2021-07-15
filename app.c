// Peut-être pas nécessaires
// #ifdef _WIN32
// #include <Windows.h>
// #else
// #include <unistd.h>
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "screen.h"
#include "mygetch.h"
#include "potager.h"
#include "plante.h"

// Initialisation des variables

char key;
int taille_potager = 10;
int curseur_x = 0, curseur_y = 0;

int score = 0;


void reverse_colors_in_potager_at(potager ppotager, int x, int y)
{
    save_cursor_position();
    reverse_colors();
    move_cursor_in_potager_to(ppotager, x, y);
    print_plante_at(ppotager, x, y);
    reverse_colors();
    restore_cursor_position();
}

int main()
{
    srand(time(NULL));
    clear_screen();

    potager p;
    p = init_potager(taille_potager);

    move_cursor_to(0, 0);
    printf("####################################\n");
    printf("### Ramassage de chou (très fun) ###\n");
    printf("####################################\n");
    printf("But : Ramasser le plus de chous en 100 mouvements.\n");
    printf("      Les chous mûrs rapportent plus de points !\n");
    printf("Touches :");
    printf("\tZQSD :\tdéplacer curseur\n\t");
    printf("\tEspace :\tcueillir plante\n\t");
    printf("\tÉchap/flèches :\tquitter\n");


    // Boucle de jeu
    print_potager(p);
    int i;
    for (i = 0; i < 100; i++)
    {
        // printf("Appuyer sur une touche : ");
        key = mygetch();
        // Si ce n'est pas un caractère échappé
        if (key != 27)
        {
            // Jeu ici
            // printf("%c (ascii : %d)\n", key, key);
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
            faire_pousser_potager(p); // fait pousser à chaque appui de touche

            reprint_potager(p);
            reverse_colors_in_potager_at(p, curseur_x, curseur_y);
            printf("Score : %d", score);
        }
        else
            break;
    }
    reset_colors();
    printf("\n");
    free_potager(&p);
}