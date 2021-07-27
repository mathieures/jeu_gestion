#ifndef MYGETCH_H
#define MYGETCH_H

// Si on est sous Windows
#ifdef _WIN32
// #include <Windows.h>
#include <conio.h>

#define mygetch _getch

// Sinon
#else
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define mygetch unix_getch

int unix_getch();

#endif


#endif