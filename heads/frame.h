#ifndef FUNCTIONS
#define FUNCTIONS

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

void frame(int (*field)[LENGTH]);

void Vertical_wall();

void Horizontal_wall();

void ShowFrame(int (*field)[LENGTH]);

void CheckLife(int (*field)[LENGTH]);

int start_screen(int (*field)[LENGTH], int *game);

int FillField(int (*field)[LENGTH], const char *filename);

#endif