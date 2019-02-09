#include <stdio.h>

int main(void){
	int stage,i,j,k;

	printf("ピラミッドを作ります。\n何段ですか:");	scanf("%d", &stage);

	for(i=1; i<=stage; i++){
		for(j=stage-i; j>=0; j--)
			putchar(' ');
		
		for(k=1; k<=(i-1)*2+1; k++)
			putchar('*');

		puts("");
	}

	return 0;
}
