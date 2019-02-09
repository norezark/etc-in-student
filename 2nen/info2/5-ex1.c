#include <stdio.h>

int main(void){
	int x, i, j;

	while(1){
		printf("正方形の幅を入力してください（奇数のみ）:");	scanf("%d", &x);
		
		if(x<=0||x%2==0){
			printf("値が不正です。\n");
			continue;
		}
		break;
	}

	for(i=1; i<=x; i++){
		for(j=1; j<=x; j++){
			if(i==1 || i==x || j==1 || j==x || i==j || i+j==x+1){
				putchar('*');
			}else{
				putchar(' ');
			}
		}
		puts("");
	}

	return 0;
}
