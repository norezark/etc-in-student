#include <stdio.h>

int main(void){
	char namef[80], names[80];

	printf("名字を入力してください: ");
	scanf("%s", namef);
	printf("下の名前を入力してください: ");
	scanf("%s", names);

	printf("あなたのイニシャルは%c.%cです。\n", namef[0], names[0]);

	return 0;
}
