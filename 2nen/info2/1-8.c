#include <stdio.h>

int main(){
	double height,range;
	puts("円柱の高さを入力してください:");
	scanf("%lf", &height);
	puts("底面の半径を入力してください:");
	scanf("%lf", &range);
	printf("円柱の体積は約%.2lfです。\n", range*range*3.1415*height);

	return 0;
}
