#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../heads/control.h"
#include "../heads/frame.h"
#include "../heads/structs.h"

void frame(int (*field)[LENGTH]) {
  Vertical_wall();
  Horizontal_wall();
  CheckLife(field);
  ShowFrame(field);
  refresh();
}

void Vertical_wall() {
  move(0, 0);
  for (int i = 0; i <= WIDTH + 2; i++) {
    move(i, 0);
    printw("%s", WALL_VERTICAL);
    move(i, LENGTH + 2);
    printw("%s", WALL_VERTICAL);
  }
}

void Horizontal_wall() {
  move(0, 0);
  for (int i = 0; i <= LENGTH + 2; i++) {
    move(0, i);
    printw("%s", WALL_HORIZONTAL);
    move(WIDTH + 2, i);
    printw("%s", WALL_HORIZONTAL);
  }
}

void CheckLife(int (*field)[LENGTH]) {
  int newField[WIDTH][LENGTH];

  for (int y = 0; y < WIDTH; y++) {
    for (int x = 0; x < LENGTH; x++) {
      int count = 0;

      for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
          if (dx == 0 && dy == 0)
            continue;

          int ny = (y + dy + WIDTH) % WIDTH;
          int nx = (x + dx + LENGTH) % LENGTH;

          if (field[ny][nx] == 1)
            count++;
        }
      }

      if (field[y][x] == 1) {
        newField[y][x] = (count == 2 || count == 3) ? 1 : 0;
      } else {
        newField[y][x] = (count == 3) ? 1 : 0;
      }
    }
  }

  for (int y = 0; y < WIDTH; y++)
    for (int x = 0; x < LENGTH; x++)
      field[y][x] = newField[y][x];
}

void ShowFrame(int (*field)[LENGTH]) {
  for (int y = 0; y < WIDTH; y++) {
    for (int x = 0; x < LENGTH; x++) {
      if (field[y][x] == 1) {
        mvprintw(y, x, "%s", LIFE);
      } else
        mvprintw(y, x, "%s", DEAD);
    }
  }
}

int start_screen(int (*field)[LENGTH], int *game){
  printw(
      "Start game (enter scenario):\n1 - sustainable scenario 1 \n2 - "
      "sustainable scenario 1 \n3 - sustainable scenario 2 \n4 - sustainable "
      "scenario 2  \n5 - sustainable scenario 3 \n6 - user input");
  char start_key = getch();

  switch (start_key) {
    case '1':
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      UserInput(field);
      break;
    case 'q':
      *game = 0;
      return 0;
    default:
      start_screen(field, game);
      break;
  }
}