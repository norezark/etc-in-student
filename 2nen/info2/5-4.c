#include <stdio.h>

int main(void){
	int side,i,j;

	printf("正方形を作ります。\n何段ですか:");	scanf("%d", &side);

	for(i=1; i<=side; i++){
		for(j=1; j<=side; j++)
			putchar('*');

		puts("");
	}

	return 0;
}
