#include <stdio.h>

int main(){
	int a,b;
	puts("二つの整数を入力してください");
	puts("整数1:");
	scanf("%d", &a);
	puts("整数2:");
	scanf("%d", &b);
	printf("それらの積は%dです\n", a*b);

	return 0;
}
