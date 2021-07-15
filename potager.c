#include "potager.h"

potager init_potager(int ptaille)
{
    potager result;
    result.taille = ptaille;
    result.pot = (plante**)calloc(ptaille, sizeof(plante*));
    
    int i, j;
    for (i = 0; i < ptaille; i++)
    {
        result.pot[i] = (plante*)calloc(ptaille, sizeof(plante));
        for (j = 0; j < ptaille; j++)
            init_emplacement(result, i, j);
    }
    return result;
}

void init_emplacement(potager ppotager, int x, int y)
{
    if (in_potager(ppotager, x, y))
    {   
        plante p;
        p = init_plante();
        ppotager.pot[x][y] = p;
    }
}

int in_potager(potager ppotager, int x, int y)
{
    return (0 <= x && x < ppotager.taille && 0 <= y && y < ppotager.taille);
}

plante* get_plante(potager ppotager, int x, int y)
{
    if (in_potager(ppotager, x, y))
        return &(ppotager.pot[y][x]); // les lignes sont en premier dans une liste de listes
    return NULL;
}

void move_cursor_in_potager_to(potager ppotager, int x, int y)
{
    if (in_potager(ppotager, x, y))
    {
        move_lines_up(ppotager.taille - y);
        move_to_column(x*2); // Bouge le curseur à la colonne x (*2 pour les espaces)
    }
}

// Gère la couleur aussi
void print_plante_at(potager ppotager, int x, int y)
{
    if (in_potager(ppotager, x, y))
    {
        // change_fg_color_to(COULEURS_PLANTES[ppotager.pot[y][x].age]);
        printf("%c", ppotager.pot[y][x].car);
        reset_colors();
    }
}

void print_potager(potager ppotager)
{
    int i, j;
    for (i = 0; i < ppotager.taille; i++)
    {
        for (j = 0; j < ppotager.taille; j++)
        {
            print_plante_at(ppotager, j, i);
            printf(" ");
        }
        printf("\n");
    }
}

// Affiche le potager à la place du précédent
void reprint_potager(potager ppotager)
{
    move_cursor_in_potager_to(ppotager, 0, 0);
    print_potager(ppotager);
}

void faire_pousser_potager(potager ppotager)
{
    int proba = 1; // en %
    int i, j;
    for (i = 0; i < ppotager.taille; i++)
        for (j = 0; j < ppotager.taille; j++)
            if (random() % 100 < proba)
            {
                plante* p;
                p = get_plante(ppotager, i, j);
                if (0 == vieillir(p))
                    deraciner(p);
            }
}

int cueillir(potager ppotager, int x, int y)
{
    // système de score ? (pour l'instant : l'âge)
    return deraciner(get_plante(ppotager, x, y));
}

/*
void detruire_plante(potager ppotager, int x, int y)
{

}
*/

void free_potager(potager* ppotager)
{
    int i;
    for (i = 0; i < ppotager->taille; i++)
        free(ppotager->pot[i]);
    free(ppotager->pot);
}