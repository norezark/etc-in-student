#include <stdio.h>

int main(){
	int month, day=0;

	printf("月を入力してください:");	scanf("%d", &month);

	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = 30;
			break;
		case 2:
			day = 28;
			break;
		default:
			puts("そのような月はありません。");
			break;
	}

	if(day) printf("%d月は%d日までです。\n", month, day);

	return 0;
}
