#include <stdio.h>

int main(void){
	int a[2][4]={1,2,3,4,5}, i, j;

	puts("各要素の値を確認します。");
	for(i=0; i<2; i++){
		for(j=0; j<4; j++){
			printf("%5d", a[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
