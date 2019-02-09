#include <stdio.h>

int min3(int a,int b,int c){
	int min=a;
	if(b<min)	min=b;
	if(c<min)	min=c;

	return min;
}

int main(void){
	int x, y, z;
	printf("3つの整数を入力してください。\n");
	printf("整数1: ");
	scanf("%d", &x);
	printf("整数2: ");
	scanf("%d", &y);
	printf("整数3: ");
	scanf("%d", &z);

	printf("最小値は%dです。\n", min3(x, y, z));

	return 0;
}
