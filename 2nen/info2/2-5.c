#include <stdio.h>

int main(){
	int x;

	printf("整数xを入力してください :");	scanf("%d", &x);

	if (x>=10 && x<=99){
		puts("2桁の数字です。");
	}else{
		puts("2桁の数字ではありません。");
	}

	return 0;
}
