#ifndef POTAGER_H
#define POTAGER_H

#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "plante.h"


typedef struct {
    plante** pot; // le terrain où sont les plantes, le potager en lui-même
    int taille;
} potager;

potager init_potager(int ptaille);
void init_emplacement(potager ppotager, int x, int y);

int in_potager(potager ppotager, int x, int y);
plante* get_plante(potager ppotager, int x, int y);
void move_cursor_in_potager_to(potager ppotager, int x, int y);

void print_plante_at(potager ppotager, int x, int y);
void print_potager(potager ppotager);
void reprint_potager(potager ppotager);

void faire_pousser_potager(void);

void free_potager(potager* ppotager);

#endif