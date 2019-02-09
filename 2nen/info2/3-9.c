#include <stdio.h>

int main(){
	int a, i=0;

	do{
		printf("1以上20以下の整数を入力してください:");	scanf("%d", &a);
	} while(a<1 || a>20);

	while(i < a){
		putchar('*');
		i++;
	}
	putchar('\n');

	return 0;
}
