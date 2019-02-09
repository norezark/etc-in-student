#include <stdio.h>

int main(void){
	int x, i, max, gusu;

	while(1){
		puts("何個のデータを入力しますか？(最大10):");
		scanf("%d", &x);
		if(x>10 || x<0){
			puts("不正な値です。\n");
			continue;
		}
		break;
	}

	int a[x];

	for(i=0; i<x; i++){
		printf("No.%d:", i+1);
		scanf("%d", &a[i]);
		
		if(i==0 || a[i]>max) max=a[i];
		if(a[i]%2==0) gusu++;
	}

	printf("最大値は%dで、偶数の値は%d個あります。\n", max, gusu);

	return 0;
}
