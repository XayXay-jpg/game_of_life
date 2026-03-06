#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../heads/control.h"
#include "../heads/structs.h"

void control(const char key, double *speed, int *game){
    switch (key)
    {
    case 'a': case 'A': *speed -= 0.01; break;
    case 'z': case 'Z': *speed += 0.01; break;
    case ' ': game = 0; break;

    default:break;
    }

}
