#ifndef CONTROL
#define CONTROL

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

void control(const char key, double *speed, int *game);

void UserInput(int (*field)[LENGTH]);

#endif