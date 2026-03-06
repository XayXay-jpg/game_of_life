#include <ncurses.h>

void keyboard_edit(int field[25][80]) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);  

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    if (max_y < 26 || max_x < 80) {
        printw("Терминал слишком мал. Нужно минимум 80x25.\n");
        printw("Текущий размер: %dx%d. Нажмите любую клавишу...", max_x, max_y);
        refresh();
        getch();
        endwin();
        return;
    }

    // Отрисовка начального состояния поля
    clear();
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            mvaddch(y, x, field[y][x] ? '1' : '0');
        }
    }
    mvprintw(25, 0, "Стрелки - перемещение, пробел - переключить, 'q' - выход");
    refresh();

    int cur_x = 0, cur_y = 0;               // начальная позиция курсора
    mvchgat(cur_y, cur_x, 1, A_REVERSE, 0, NULL); // выделение

    int ch;
    while ((ch = getch()) != 'q') {
        // Снять выделение со старой позиции
        mvchgat(cur_y, cur_x, 1, A_NORMAL, 0, NULL);

        switch (ch) {
            case KEY_UP:
                if (cur_y > 0) cur_y--;
                break;
            case KEY_DOWN:
                if (cur_y < 24) cur_y++;
                break;
            case KEY_LEFT:
                if (cur_x > 0) cur_x--;
                break;
            case KEY_RIGHT:
                if (cur_x < 79) cur_x++;
                break;
            case ' ':
                field[cur_y][cur_x] = !field[cur_y][cur_x];
                mvaddch(cur_y, cur_x, field[cur_y][cur_x] ? '1' : '0');
                break;
            // При желании можно добавить другие клавиши
        }

        // Выделить новую позицию
        mvchgat(cur_y, cur_x, 1, A_REVERSE, 0, NULL);
        move(cur_y, cur_x); // переместить физический курсор (не обязательно, но эстетично)
        refresh();
    }

    endwin();
}

int main() {
    int field[25][80] = {0};  // инициализация нулями

    // Можно предварительно заполнить поле, например, случайно или из файла
    // ...

    keyboard_edit(field);     // вызов функции редактирования

    // После завершения массив field содержит изменённые данные
    // Здесь можно сохранить результат в файл или передать дальше
    return 0;
}