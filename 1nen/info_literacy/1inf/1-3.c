#include <stdio.h>

int main(){
	float l,h,s;
	printf("四角形の底辺を入力してください>");
	scanf("%f",&l);
	printf("四角形の高さを入力してください>");
	scanf("%f",&h);
	s = l * h;
	printf("面積は%fです。\n",s);
	return 0;
}
