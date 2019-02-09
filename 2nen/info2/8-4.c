#include <stdio.h>

int main(void){
	char ch;
	printf("文字を1つ入力してください: ");
	ch = getchar();
	if(ch==EOF){
		puts("EOFです。");
	}else{
		printf("入力された文字は%cです。\n");
		printf("文字コードは10進数で%d、16進数で%xです。\n", ch, ch);
	}

	return 0;
}
