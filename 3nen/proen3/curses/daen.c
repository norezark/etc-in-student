#include <ncurses.h>
#include <string.h>
#include <math.h>

int main(void){
    int w, h, x ,y;
    float i;
    initscr();

    getmaxyx(stdscr, h, w);

    clear();
    for(i = 0; i <= 90; i += 0.1){
        x = (int)round((h/2)*cos(i*(M_PI/180)));
        y = (int)round((w/2)*sin(i*(M_PI/180)));
        mvaddch(x+(int)(h/2)-1, y+(int)(w/2)-1, '*');
        //mvaddch(-x+(int)(h/2), y+(int)(w/2)-1, '*');
        //mvaddch(x+(int)(h/2)-1, -y+(int)(w/2), '*');
        //mvaddch(-x+(int)(h/2), -y+(int)(w/2), '*');
    }
    refresh();

    noecho();
    getch();

    endwin();

    return 0;
}
