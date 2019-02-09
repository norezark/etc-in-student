#include <stdio.h>
#include <math.h>

int main(){
	float x,h,r;
	printf("三角形の底辺を入力してください>");
	scanf("%f",&x);
	printf("三角形の高さを入力してください>");
	scanf("%f",&h);
	r = sqrt(x*x + h*h);
	printf("三角形の斜辺は%fです\n",r);
	return 0;
}
