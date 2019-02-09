#include <stdio.h>

int getnextday(int month, int day, int *nmonth, int *nday){
		int flag=0, i=0;
		if(month>12||month<1||day<1)	return -1;
		switch(month){
				case 4:
				case 6:
				case 9:
				case 11:
						flag=1;
						if(day>30)
								return -1;
						else if(day==30)
								i=1;
						break;
				case 2:
						flag=2;
						if(day>28)
								return -1;
						else if(day==28)
								i=1;
						break;
				default:
						flag=3;
						if(day>31)
								return -1;
						else if(day==31)
								i=1;
						break;
		}
		if(i){
				*nday=1;
				if(month==12){
						*nmonth=1;
				}else{
						*nmonth=month+1;
				}
		}else{
				*nday=day+1;
				*nmonth=month;
		}
		return 0;
}

int main(void) {
		int m, d, nm, nd, ret;
		while(1) {
				printf("日付を入力してください: ");
				scanf(" %d/%d", &m, &d);

				ret = getnextday(m, d, &nm, &nd);
				if(ret<0)
						puts("不正な値です。");
				else
						printf("翌日は%d月%d日です。\n", nm, nd);
		}
		return 0;
}
