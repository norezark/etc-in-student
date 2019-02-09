#include <stdio.h>

int main(void){
	char ch;
	int count=0;
	puts("文字を入力してください。");
	while((ch=getchar()) != EOF){
		if(ch>='0' && ch<='9')	count++;
	}
	printf("入力された文字の中に、数字は%d個含まれています。\n", count);

	return 0;
}
