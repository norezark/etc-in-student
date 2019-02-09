#include <stdio.h>

int main(){
	float r,s;
	printf("円の半径を入力してください>");
	scanf("%f", &r);
	s = 3.141592 * r * r;
	printf("半径%fの円の半径は%fです。\n",r,s);
	return 0;
}
	
