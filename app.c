// Pour 
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
    printf("Début du jeu\nTouches :");
    printf("\tZQSD :\tdéplacer curseur\n\t");
    printf("\tÉchap/flèches :\tquitter\n");


    // Boucle de jeu
    print_potager(p);
    while (1)
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
                    // vieillir(get_plante(p, curseur_x, curseur_y));
                    // printf("nouvel âge : %d", vieillir(get_plante(p, 2, 2)));
                    break;
                default:
                    break;
            }
            faire_pousser_potager();

            reprint_potager(p);
            reverse_colors_in_potager_at(p, curseur_x, curseur_y);
        }
        else
        {
            reset_colors();
            printf("fin\n");
            break;
        }
    }
    free_potager(&p);
}