#include <stdio.h>

int main(){
	double d,y;
	printf("日数を入力して下さい>");
	scanf("%lf",&d);
	y = d / 365;
	printf("%f日は%f年です。\n",d,y);
	return 0;
}
