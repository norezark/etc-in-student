#include <stdio.h>

int main(void){
	int num;
	printf("10進数の整数を入力してください: ");
	scanf("%d", &num);
	printf("10進数の%dは8進数で%o、16進数で%Xです。\n", num, num, num);

	return 0;
}
