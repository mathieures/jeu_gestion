#include "plante.h"

plante init_plante(void)
{
    plante p;
    p.age = 0;
    p.car = AGES[p.age];
    return p;
}

int vieillir(plante* pplante)
{
    if (pplante->age != AGE_MAX)
        pplante->car = AGES[++pplante->age];
    return pplante->age;
}