#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <math.h>
#include <ncurses.h>

int main(void){
    int n, width, height, r;
    double x, y, h = 0, i;

    printf("回数: ");
    scanf("%d", &n);

    initscr();
    curs_set(0);
    getmaxyx(stdscr, height, width);
    clear();

    if(height < width){
        r = height;
    }else{
        r = width;
    }

    for(i = 0; i <= 90; i+=0.2){
        x = round((r-1)*cos(i*(M_PI/180)));
        y = round((r*2)*sin(i*(M_PI/180)));
        mvaddch(x, y, '*');
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    srand((unsigned)time(NULL));
    for(i=0; i<n; i++){
        x = (double)rand()/(1.0 + RAND_MAX);
        y = (double)rand()/(1.0 + RAND_MAX);
        if(x*x + y*y <= 1){
            h+=1;
            attrset(COLOR_PAIR(2));
        }else{
            attrset(COLOR_PAIR(1));
        }
        mvaddch(r*x, r*y*2, '.');
    }

    refresh();
    noecho();
    getch();
    endwin();

    printf("π = %.31f\nM_PI - π = %.31f\n", (h/n)*4, M_PI - (h/n)*4);

    return 0;
}
