#include <stdio.h>

int main(){
	int x,y;
	puts("整数xを入力してください:");
	scanf("%d", &x);
	puts("整数yを入力してください:");
	scanf("%d", &y);
	printf("yはxの%.1lf%です。\n", (double)y/x*100);
	
	return 0;
}
