#include <stdio.h>

void delnumchars(char *s){
	char *p = s;
	while(*p!='\0'){
		if((*p<'9'&&*p>'0') == 0){
			*s = *p;
			s++;
		}
		p++;
	}
	*s='\0';
}

int main(void){
	char s[] = "abc123DE45";
	printf("元の文字列は%sです。\n", s);
	delnumchars(s);
	printf("数値を削除した文字列は%sです。\n", s);
	return 0;
}
