#include <stdio.h>

int main(void){
	int n, i, s=0;
	float a;

	puts("3つの整数を入力してください。");

	for(i=0; i<3; i++){
		printf("%d番目:", i+1);	scanf("%d",&n);
		s += n;
	}
	a = s/3.0;

	printf("合計値は%dです。\n平均値は%.1fです。\n", s, a);

	return 0;
}
