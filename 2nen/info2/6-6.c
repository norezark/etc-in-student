#include <stdio.h>

int main(void){
	int a[4][2], i, j, sum1, sum2=0, sum3=0;

	for(i=0; i<4; i++){
			printf("No.%dの国語の点数は: ", i+1);
			scanf("%d", &a[i][0]);
			printf("No.%dの数学の点数は: ", i+1);
			scanf("%d", &a[i][1]);
	}

	puts("      国語 数学 合計  平均");

	for(i=0; i<4; i++){
		printf("No.%2d", i+1);
		sum1 = 0;
		for(j=0; j<2; j++){
			printf(" %4d", a[i][j]);
			sum1 += a[i][j];
		}
		printf("%5.1d %5.1f\n", sum1, sum1/2.0);
	}
	for(i=0; i<4; i++){
		sum2 += a[i][0];
		sum3 += a[i][1];
	}

	printf("合計: %4d %4d\n平均: %4.1f %4.1f\n", sum2, sum3, sum2/4.0, sum3/4.0);

	return 0;
}
