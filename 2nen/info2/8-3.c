#include <stdio.h>

int main(void){
	int num;
	printf("16進数の整数を入力してください: ");
	scanf("%x", &num);
	printf("16進数の%Xは10進数で%dです。\n", num, num);

	return 0;
}
