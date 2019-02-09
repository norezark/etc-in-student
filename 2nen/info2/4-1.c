#include <stdio.h>

int main(){
	int a, i;

	printf("整数を入力してください:");	scanf("%d",&a);
	
	for(i=0; i<a; i++){
		putchar('#');
	}
	puts("");

	return 0;
}
