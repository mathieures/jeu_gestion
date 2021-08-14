#include "mygetch.h"
#ifndef _WIN32

int unix_getch(void)
{
   struct termios oldt, newt;
   int ch;
   tcgetattr(STDIN_FILENO, &oldt);

   newt = oldt;
   newt.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newt);

   ch = getchar();
   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

   return ch;
}

#endif