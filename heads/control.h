#ifndef CONTROL
#define CONTROL

#define LENGTH 80
#define WIDTH 25

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

void control(const char key, double *speed, int *game);

void UserInput(int (*field)[LENGTH]);

#endif