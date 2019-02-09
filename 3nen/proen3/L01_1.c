#include <stdio.h>

int main(void){
	int a, b, c, temp;

	printf("入力: ");
	scanf("%d %d %d", &a, &b, &c);

	if(a<b){
		temp = a;
		a = b;
		b = temp;
	}
	if(b<c){
		temp = b;
		b = c;
		c = temp;
	}

	printf("出力: %d %d %d\n", a, b, c);

	return 0;
}
