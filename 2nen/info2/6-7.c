#include <stdio.h>

int main(void){
	int a, i, j;

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
			break;
		}
	}

	puts("-- 成績分布 --");

	for(i=0; i<4; i++){
		switch(i){
			case 0:
				printf("優　: ");
				for(j=0; j<a; j++)	if(tensuu[j]>=80)	putchar('*');
				break;
			case 1:
				printf("良　: ");
				for(j=0; j<a; j++)	if(tensuu[j]/10==7)	putchar('*');
				break;
			case 2:
				printf("可　: ");
				for(j=0; j<a; j++)	if(tensuu[j]/10==6)	putchar('*');
				break;
			case 3:
				printf("不可: ");
				for(j=0; j<a; j++)	if(tensuu[j]<60)	putchar('*');
				break;
		}
		puts("");
	}

	return 0;
}
