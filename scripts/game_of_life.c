#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../heads/functions.h"
#include "../heads/structs.h"

int main(void) {
  int fact = 1, game = 1;
  int *field[WIDTH][LENGTH];
  initscr();
  noecho();
//   while (game) {
    timeout(50 * fact);
    struct Position pos;
    frame(field);
//   }

  endwin();
  return 0;
}