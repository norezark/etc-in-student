#include <stdio.h>

int main(){
	float uw,dw,h,s;
	printf("台形の上底を入力してください>");
	scanf("%f",&uw);
	printf("台形の下底を入力してください>");
	scanf("%f",&dw);
	printf("台形の高さを入力してください>");
	scanf("%f",&h);
	s = (uw + dw) * h / 2;
	printf("台形の面積は%fです\n",s);
	return 0;
}
