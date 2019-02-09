#include <stdio.h>

void hidechar(char s[], char c){
	int i;
	for(i=0; s[i]!='\0'; i++)
		if(s[i]==c)	s[i] = '_';
}

int main(void){
	char s[80], c;
	printf("文字列を入力してください: ");
	scanf("%s", s);
	printf("置き換える対象の文字を入力してください: ");
	scanf(" %c", &c);
	hidechar(s, c);
	puts(s);

	return 0;
}
