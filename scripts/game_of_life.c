#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../heads/control.h"
#include "../heads/frame.h"
#include "../heads/structs.h"

int main(void) {
  double fact = -1;
  int game = 1;
  int field[WIDTH][LENGTH] = {0};

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  timeout(50 * fact);

  while (game) {
    if(start_screen(field, &game)){
      char key = getch();
      control(key, &fact, &game);
      frame(field);
    }
  }

  endwin();
  return 0;
}