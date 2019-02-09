#include <stdio.h>

double average(double n, double m){
	double a;
	a = (n+m)/2;

	return a;
}

int main(void){
	double x, y;
	printf("実数を2つ入力してください。\n");
	printf("実数1: ");
	scanf("%lf", &x);
	printf("実数2: ");
	scanf("%lf", &y);

	printf("平均値は%fです。\n", average(x, y));

	return 0;
}
