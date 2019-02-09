#include <stdio.h>

int main(void)
{
	int i=2, no;

	printf("正の整数を入力してください:");
	scanf("%d", &no);

	while(i <= no){
		printf("%d ", i);
		i *= 2;
	}
	printf("\n");

	return 0;
}
