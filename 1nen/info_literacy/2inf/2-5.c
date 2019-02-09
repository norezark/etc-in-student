#include <stdio.h>

int main(){
	double a,b,c,d,s,m;
	printf("テストの点数を入力して下さい（その1）>");
	scanf("%lf",&a);
	printf("テストの点数を入力して下さい（その2）>");
	scanf("%lf",&b);
	printf("テストの点数を入力して下さい（その3）>");
	scanf("%lf",&c);
	printf("テストの点数を入力して下さい（その4）>");
	scanf("%lf",&d);
	s = a + b + c + d;
	m = s * 1/4;
	printf("テストの合計点数は%lf点、平均点は%lf点です。\n",s,m);
	return 0;
}
