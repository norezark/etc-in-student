#include <stdio.h>

int main(void){
	int skip,i,ex=0;

	printf("何の倍数をスキップしますか？:");	scanf("%d",&skip);

	for(i=1; i<=10; i++){
		if(i%skip==0) continue;

		printf("%d ", i);
		ex++;
	}

	printf("\n全部で%d個の数値を出力しました。\n", ex);

	return 0;
}
