#include <stdio.h>

int main(void){
	int stage, i, j, k;

	printf("下向き数字ピラミッドを作ります。\n何段ですか:");
	scanf("%d", &stage);
	
	for(i=1; i<=stage; i++){
		for(j=i; j>0; j--)
			putchar(' ');
		
		for(k=1; k<=(stage-i)*2+1; k++)
			printf("%d", i%10);

		puts("");
	}

	return 0;
}
