/*
- viellir
- disparaître (ou inclus dans vieillir ?)

Exemple d'étapes d'une plante :
    0) [une espace]
    1) .
    2) o
    3) O
    4) 0

*/
#ifndef PLANTE_H
#define PLANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char AGES[] = ".oO0"; // statique car voulu seulement dans plante.c
static const int AGE_MAX = strlen(AGES) - 1; // indice maximum de la chaîne AGES

typedef struct {
    int age;
    char car;
} plante;

plante create_plante(void);
void update_plante_car(plante* pplante);
int vieillir(plante* pplante);
int deraciner(plante* pplante);

#endif