#include <stdio.h>

int main(){
	int height;
	puts("身長(cm)を入力してください:");
	scanf("%d", &height);
	printf("標準体重は%.1lfです。\n", (double)height*height/10000*22);

	return 0;
}
