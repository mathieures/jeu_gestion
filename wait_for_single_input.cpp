#include <iostream>
#include "mygetch.h"

int main()
{
   char c;
   printf("Entrer un caractère : ");
   c = mygetch();
   printf("\nascii : %d, caractère : %c\n", c, c);

   return 0;
}