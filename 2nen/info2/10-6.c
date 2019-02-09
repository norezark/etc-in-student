#include <stdio.h>
#include <string.h>

void gethead(char *s, int x){
	if(x > strlen(s))
		return;
	*(s+x) = '\0';
}

int main(void){
	char s[80];
	int x;

	printf("文字列は?: ");
	scanf("%s", s);
	printf("文字数は?: ");
	scanf("%d", &x);
	gethead(s, x);
	puts(s);
	return 0;
}
