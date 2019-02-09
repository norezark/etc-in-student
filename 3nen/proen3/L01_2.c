#include <stdio.h>

int main(void){
	int num[10],i;

	for(i=0; i<10; i++)
		scanf("%d", &num[i]);

	for(i=0; i<10; i++)
		printf("%d ", num[9-i]);

	puts("");

	return 0;
}
