#include <stdio.h>

int main(){
	int a=0,n;

	while(a==0){
		printf("整数を入力してください:");	scanf("%d", &n);
		if(n==0){
			puts("その数は0です。");
		} else if(n>0){
			puts("その数は正です。");
		} else {
			puts("その数は負です。");
		}
		
		printf("続けますか？(Yes:0/No:9):"); scanf("%d", &a);
	}

	return 0;
}
