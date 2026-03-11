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
    for (int i = 0; i <= WIDTH + 1; i++) {
        mvprintw(i, 0, "%s", WALL_VERTICAL);
        mvprintw(i, LENGTH + 1, "%s", WALL_VERTICAL);
    }
}

void Horizontal_wall() {
    for (int i = 0; i <= LENGTH + 1; i++) {
        mvprintw(0, i, "%s", WALL_HORIZONTAL);
        mvprintw(WIDTH + 1, i, "%s", WALL_HORIZONTAL);
    }
}

void CheckLife(int (*field)[LENGTH]) {
    int newField[WIDTH][LENGTH];

    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < LENGTH; x++) {
            int count = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;

                    int ny = (y + dy + WIDTH) % WIDTH;
                    int nx = (x + dx + LENGTH) % LENGTH;

                    if (field[ny][nx] == 1) count++;
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
        for (int x = 0; x < LENGTH; x++) field[y][x] = newField[y][x];
}

void ShowFrame(int (*field)[LENGTH]) {
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < LENGTH; x++) {
            if (field[y][x] == 1) {
                mvprintw(y + 1, x + 1, "%s", LIFE);
            } else {
                mvprintw(y + 1, x + 1, "%s", DEAD);
            }
        }
    }
}

int start_screen(int (*field)[LENGTH], int* game) {
    clear();
    printw(
        "Start game (enter scenario):\n"
        "1 -  scenario 1\n"
        "2 -  scenario 2\n"
        "3 -  scenario 3\n"
        "4 -  scenario 4\n"
        "5 -  scenario 5\n"
        "6 - user input\n"
        "Press 'q' to quit\n");
    refresh();

    while (1) {
        char start_key = getch();
        switch (start_key) {
            char* filename;
            case '1':
                filename = "scenario/blocks_80x25.txt";
                if (FillField(field, filename)) {
                    clear();
                    printw("error");
                    getch();
                }
                return 1;
            case '2':
                filename = "scenario/glider_gun_80x25.txt";
                if (FillField(field, filename)) {
                    clear();
                    printw("error");
                    getch();
                }
                return 1;
            case '3':
                filename = "scenario/gliders_80x25.txt";
                if (FillField(field, filename)) {
                    clear();
                    printw("error");
                    getch();
                }
                return 1;
            case '4':
                filename = "scenario/oscillators_80x25.txt.txt";
                if (FillField(field, filename)) {
                    clear();
                    printw("error");
                    getch();
                }
                return 1;
            case '5':
                filename = "scenario/rpentomino_80x25.txt";
                if (FillField(field, filename)) {
                    clear();
                    printw("error");
                    getch();
                };
                return 1;
            case '6':
                UserInput(field);
                return 1;
            case 'q':
                *game = 0;
                return 0;
            default:
                break;
        }
    }
}

int FillField(int (*field)[LENGTH], const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return 1;

    for (int row = 0; row < WIDTH; ++row) {
        for (int col = 0; col < LENGTH; ++col) {
            int ch = fgetc(f);
            if (ch == EOF) {
                fclose(f);
                return 1;
            }
            if (ch == '\n') {
                fclose(f);
                return 1;
            }
            if (ch != '0' && ch != '1') {
                fclose(f);
                return 1;
            }
            field[row][col] = (ch == '1') ? 1 : 0;
        }

        int ch = fgetc(f);
        if (ch == EOF) {
            if (row == WIDTH - 1) {
                break;
            } else {
                fclose(f);
                return 1;
            }
        }
        if (ch != '\n') {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
