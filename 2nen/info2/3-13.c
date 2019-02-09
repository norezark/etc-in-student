#include <stdio.h>

int main(){
	int a, i=0, max, min;

	do{
		printf("整数を入力してください:");	scanf("%d", &a);
		if(a<0) break;
		if(max<a || i==0) max = a;
		if(min>a || i==0) min = a;
		i = 1;
	}while(1);

	if(i==1){
		printf("最大値は%d、最小値は%dです。\n", max, min);
	}else{
		puts("有効な値が1つも入力されていません。");
	}

	return 0;
}
