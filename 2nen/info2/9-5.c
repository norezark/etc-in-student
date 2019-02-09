#include <stdio.h>

int str_char(const char s[], int c){
	int i, j=0;
	for(i=0; s[i]!='\0'; i++)
		if(s[i]==c) j++;

	return j;
}

int main(void){
	char s[80], c, loc;
	printf("文字列を入力してください: ");
	scanf("%s", s);
	printf("探したい文字を入力してください: ");
	scanf(" %c", &c);

	if(str_char(s, c)>=0){
		printf("%sの中に%cが最初に出現する添字は%dです。\n", s, c, str_char(s, c));
	}else{
		puts("その文字は含まれません。");
	}
	return 0;
}
