#include "plante.h"

plante init_plante(void)
{
    plante p;
    p.age = 0;
    p.car = AGES[p.age];
    return p;
}

void update_plante_car(plante* pplante)
{
    pplante->car = AGES[pplante->age];
}

// Renvoie l'âge pour savoir si on la déracine (0 : âge max, donc couic)
int vieillir(plante* pplante)
{
    if (pplante->age != AGE_MAX)
    {
        pplante->age++;
        update_plante_car(pplante);
        return pplante->age;
    }
    return 0;
}

int deraciner(plante* pplante)
{
    int result;
    result = pplante->age;
    pplante->age = 0;
    update_plante_car(pplante);
    return result;
}