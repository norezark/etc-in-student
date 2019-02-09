#include <stdio.h>

int main(void){
	int a[10][10]={}, i, j;

	for(i=0; i<10; i++){
		a[i][i] = 1;
	}

	puts("各要素の値を確認します。");
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			printf("%5d", a[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
