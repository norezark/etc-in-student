#include <stdio.h>

int main(){
	int a, sum=0, i=0;

	do{
		printf("%d人目の体重は:", ++i);	scanf("%d", &a);
		sum += a;
	} while(sum>=0 && sum <=300);

	printf("合計重量が%dkgとなり%dkgオーバーしました。\n%d人目の人は乗ることができません。\n", sum, sum-300, i);

	return 0;
}
