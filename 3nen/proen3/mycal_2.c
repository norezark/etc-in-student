#include <stdlib.h>
#include <stdio.h>
#ifndef MINYEAR
#include "mycal_max.h"
#endif

//int maxday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void cal2(char *m, char *y){
    int month, year;
    if(((month = atoi(m)) == 0) || ((year = atoi(y)) == 0)){
        calhelp();
    }else if(year < MINYEAR){
        printf("対応していない年です。\n");
        return;
    }else if((month<1) || (month>12)){
        printf("正しい値を入力してください。\n");
        return;
    }else{
        printf("\t%d 月\n", month);
        printf("日 月 火 水 木 金 土\n");

        int tm = month, ty = year;
        if(month <= 2){
            tm = month + 12;
            ty = year - 1;
        }
        int tmp = ((1+(26*(tm+1)/10)+ty%100+(ty%100)/4+5*(ty/100)+(ty/100)/4+5)%7+1)%7;
        int t = tmp;
        while(--t >= 0) printf("   ");
        int day = 0;
        while(++day){
            if(month == 2 && uruu(year)){
                if(day>maxday[month-1]+1) break;
            }else{
                if(day>maxday[month-1]) break;
            }
            printf("%2d ", day);
            if((day+tmp) % 7 == 0) printf("\n");
        }
        printf("\n\n");
    }
}
