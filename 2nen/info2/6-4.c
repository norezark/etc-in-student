#include <stdio.h>
#include <math.h>

int main(void){
	int a[5][3], i, j;

	for(i=1; i<=5; i++){
		for(j=1; j<=3; j++){
			a[i-1][j-1] = pow(i, j);
		}
	}

	puts("各要素の値を確認します。");
	for(i=0; i<5; i++){
		for(j=0; j<3; j++){
			printf("%5d", a[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
