#include <stdlib.h>
#ifndef MAXYEAR
#include "mycal_max.h"
#endif
#ifndef CALHELP
#include "mycal_help.c"
#endif
#ifndef CALURUU
#include "mycal_uruu.c"
#endif

void cal1(char *y){
    int year;
    if((year = atoi(y)) == 0){
        calhelp();
        return;
    }else{
        if(year < MINYEAR){
            printf("対応していない年です。\n");
            return;
        }else{
            int month;
            for(month=1; month<=12; month++){
                printf("\t%d 月\n", month);
                printf("日 月 火 水 木 金 土\n");

                int tm, ty;
                if(month <= 2){
                    tm = month + 12;
                    ty = year - 1;
                }
                int tmp = (1+(int)(26*(tm+1)/10)+ty%100+(ty%100)/4-2*(int)(ty/100)+(int)((int)(ty/100))/4)%7;
                while(tmp--) printf("   ");

                int day = 0;
                while(++day){
                    if(uruu(year) && month == 2){
                         if(day>(maxday[month-1]-1)) break;
                    }else{
                        if(day>maxday[month-1]) break;
                    }
                    printf("%2d ", day);
                    if((day+tmp) % 7 == 0) printf("\n");
                }
                printf("\n\n");
            }
        }
    }
}
