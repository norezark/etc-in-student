#include <stdio.h>

int main(){
	int age;
	printf("あなたの年齢を入力して下さい>");
	scanf("%d",&age);
	if (age >= 18) {
		printf("あなたには選挙権があります。\n");
	}else{
		printf("あなたには選挙権がありません。\n");
	}
	return 0;
}
