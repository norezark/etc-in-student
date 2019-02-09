#include <stdio.h>

int main(void){
	char str[80], c;
	int i, num=0;

	printf("文字列を入力してください: ");
	scanf("%s", str);
	printf("探したい文字を入力してください: ");
	scanf(" %c", &c);

	for(i=0; str[i]!='\0'; i++){
		if(str[i] == c)
			num++;
	}

	printf("文字列%sの中には文字%cが%d個含まれています。\n", str, c, num);

	return 0;
}
