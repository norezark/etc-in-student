#include <ncurses.h>
#include <math.h>

int main(void){
    int n, h, w;
    double x, y;

    initscr();
    clear();
    nocbreak();
    addstr("syuki: ");
    scanw("%d", &n);

    clear();
    curs_set(0);
    getmaxyx(stdscr, h, w);
    for(y = 0; y <= w; y++){
        x = (h/2-1)*sin((y/w)*n*2*M_PI);
        mvaddch((int)round(x)+h/2-1, y, '*');
    }

    refresh();
    noecho();
    getch();
    endwin();

    return 0;
}
