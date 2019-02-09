#include <stdio.h>

int main(){
	int a,b;
	puts("整数aを入力してください：");
	scanf("%d", &a);
	puts("整数bを入力してください：");
	scanf("%d", &b);
	printf("a + b: %d\na - b: %d\na * b: %d\na / b: %d\na %% b: %d\n", a+b, a-b, a*b, a/b, a%b);
	return 0;
}
