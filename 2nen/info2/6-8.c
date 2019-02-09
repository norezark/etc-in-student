#include <stdio.h>

int main(void){
	int a, i, j, max=0, min=100, sum=0;

	while(1){
		printf("人数を入力してください: ");	scanf("%d", &a);

		if(a<=0){
			puts("値が不正です。");
			continue;
		}
		break;
	}
	int tensuu[a];

	printf("%d人の人数を入力してください。\n", a);

	for(i=0; i<a; i++){
		printf("No.%2d: ", i+1);
		while(1){
			scanf("%d", &tensuu[i]);
			if(tensuu[i]<0 || tensuu[i]>100){
				puts("不正な値です。");
				continue;
			}
			if(tensuu[i]>max)	max = tensuu[i];
			if(tensuu[i]<min)	min = tensuu[i];
			sum += tensuu[i];
			break;
		}
	}

	puts("-- 成績分布 --");
	printf("優　: ");
	for(j=0; j<a; j++)	if(tensuu[j]>=80)	printf("%d ", j+1);
	printf("\n良　: ");
	for(j=0; j<a; j++)	if(tensuu[j]/10==7)	printf("%d ", j+1);
	printf("\n可　: ");
	for(j=0; j<a; j++)	if(tensuu[j]/10==6)	printf("%d ", j+1);
	printf("\n不可: ");
	for(j=0; j<a; j++)	if(tensuu[j]<60)	printf("%d ", j+1);
	puts("");

	puts("-----");
	printf("最高点:%3d点", max);
	for(i=0; i<a; i++)	if(tensuu[i]==max)	printf(" [No.%d]", i+1);
	printf("\n最低点:%3d点", min);
	for(i=0; i<a; i++)	if(tensuu[i]==min)	printf(" [No.%d]", i+1);
	printf("\n平均点:%5.1f点\n", (double)sum/a);

	return 0;
}
