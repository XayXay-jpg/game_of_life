#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../heads/frame.h"
#include "../heads/control.h"
#include "../heads/structs.h"

int main(void) {
  double fact = -1; 
  int game = 1;
  int field[WIDTH][LENGTH];
  initscr();
  noecho();
  cbreak();
  while (game) {
    char key = getch();
    printw("Start game:\n ");
    switch (key){
    case '1': break;
    case '2': break;
    case '3': break;
    case '4': break;
    case '5': break;
    case '6':  break;
    default: break;
    }
    control(key, &fact, &game);
    timeout(50 * fact);
    frame(field);
  }

  endwin();
  return 0;
}