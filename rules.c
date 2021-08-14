#include "rules.h"

void print_rules(int max_turns)
{
    printf("######################################################################\n");
    printf("####### Savez-vous cueillir des choux a la mode de chez nous ? #######\n");
    printf("######################################################################\n");
    
    printf("Objectif :");
    printf("\tRamasser le plus de choux en exactement %d mouvements\n", max_turns);
    printf("\t\tPlus un chou est gros, plus il rapporte de points !\n");
    
    printf("Touches :");
    printf("\tZQSD :\t\tdeplacer curseur\n");
    printf("\t\tEspace :\tcueillir chou\n");
    printf("\t\tL :\t\tclassement\n");
    printf("\t\tEchap/fleches :\tquitter\n");
}