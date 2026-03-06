#ifndef FUNCTIONS
#define FUNCTIONS

#define LENGTH 80
#define WIDTH 25

#include "struct.h"

void frame(int (*field)[LENGTH]);

void Vertical_wall();

void Horizontal_wall();

void ShowFrame(int (*field)[LENGTH]);

void CheckLife(int (*field)[LENGTH]);

#endif