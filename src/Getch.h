#ifndef Getch_h
#define Getch_h

#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

int getch();
int kbhit();

#endif
