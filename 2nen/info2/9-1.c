#include <stdio.h>

int main(void){
	char name[80];

	printf("名前を入力してください: ");
	scanf("%s", name);

	printf("%sさん、こんにちは。\n", name);

	return 0;
}
