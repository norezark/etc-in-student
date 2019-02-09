#include <stdio.h>

int main(){
	int n, s=0, i;

	printf("nの値:");	scanf("%d", &n);
	
	for(i=0; i<=n; i++){
		s += i;
	}

	printf("1から%dまでの和は%dです。\n", n, s);

	return 0;
}
