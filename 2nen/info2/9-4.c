#include <stdio.h>

int getlen(const char s[]){
	int len=0;
	while(s[len]!='\0') len++;
	return len;
}

int main(void){
	printf("123の長さ: %d\n", getlen("123"));
	printf("abcdsの長さ: %d\n", getlen("abcde"));
	return 0;
}
