#include <stdio.h>

int main(){
	int x;
	printf("値を入力してください: ");	scanf("%d", &x);
	
	if (x==0){
		puts("0です。");
	}else{
		if (x < 0){
			puts("負の値です。");
		}else{
			puts("正の値です。");
		}
	}

	return 0;
}
