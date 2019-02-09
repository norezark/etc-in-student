#include <stdio.h>

int main(void)
{
	double a,b,s;
	printf("三角形の底辺を入力して下さい>");
	scanf("%lf",&a);
	printf("三角形の高さを入力して下さい>");
	scanf("%lf",&b);
	s = a * b * 1/2;
	printf("面積は %lf です。\n",s);
	return 0;
}
