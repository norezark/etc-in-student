#include <stdio.h>

int main(void){
	int ch;
	while(1){
		if(ch=='\n') continue;
		printf("アルファベットの文字を1つ入力してください: ");
		if(((ch=getchar())<'A'||ch>'Z')&&(ch<'a'||ch>'z'))
			puts("不正な入力です。");
		else
			break;
	}

	if(ch>='a'&&ch<='z')
		printf("%cの大文字は%cです。\n", ch, ch-('a'-'A'));
	else
		printf("%cの小文字は%cです。\n", ch, ch+('a'-'A'));

	return 0;
}
