#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "heads/control.h"
#include "heads/frame.h"
#include "heads/structs.h"

int main(void) {
    double speed = 1.0;
    int game = 1;
    int field[WIDTH][LENGTH] = {0};

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    if (start_screen(field, &game) == 0 || game == 0) {
        endwin();
        return 0;
    }

    timeout(50 * speed);

    while (game) {
        int key = getch();
        if (key != ERR) {
            control((char)key, &speed, &game);
            timeout(50 * speed);
        }
        frame(field);
    }

    endwin();
    return 0;
}