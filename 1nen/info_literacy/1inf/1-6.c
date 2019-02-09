#include <stdio.h>

int main(){
	float x,y;
	printf("xを入力してください>");
	scanf("%f",&x);
	y = 3*x*x*x + 4*x + 6;
	printf("yは%fです\n",y);
	return 0;
}
