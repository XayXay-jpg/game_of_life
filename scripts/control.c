#include "../heads/control.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../heads/frame.h"
#include "../heads/structs.h"

void control(const char key, double* speed, int* game) {
    switch (key) {
        case 'a':
        case 'A':
            if (*speed > 0.01) *speed -= 0.1;
            break;
        case 'z':
        case 'Z':
            *speed += 0.1;
            break;
        case ' ':
            *game = 0;
            break;
        default:
            break;
    }
}

void UserInput(int (*field)[LENGTH]) {
    clear();
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < LENGTH; x++) {
            mvaddch(y, x, field[y][x] ? '1' : '0');
        }
    }
    mvprintw(WIDTH, 0, "Arrows - move cursor | Space - toggle cell | 'q' - back");
    refresh();

    int cur_x = 0, cur_y = 0;
    mvchgat(cur_y, cur_x, 1, A_REVERSE, 0, NULL);

    int ch;
    while ((ch = getch()) != 'q') {
        mvchgat(cur_y, cur_x, 1, A_NORMAL, 0, NULL);

        switch (ch) {
            case KEY_UP:
                if (cur_y > 0) cur_y--;
                break;
            case KEY_DOWN:
                if (cur_y < WIDTH - 1) cur_y++;
                break;
            case KEY_LEFT:
                if (cur_x > 0) cur_x--;
                break;
            case KEY_RIGHT:
                if (cur_x < LENGTH - 1) cur_x++;
                break;
            case ' ':
                field[cur_y][cur_x] = !field[cur_y][cur_x];
                mvaddch(cur_y, cur_x, field[cur_y][cur_x] ? '1' : '0');
                break;
        }
        mvchgat(cur_y, cur_x, 1, A_REVERSE, 0, NULL);
        move(cur_y, cur_x);
        refresh();
    }
}
