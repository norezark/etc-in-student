#include <stdio.h>

int main(void){
	int min, max, w, i;

	printf("何cmから:");	scanf("%d", &min);
	printf("何cmまで:");	scanf("%d", &max);
	printf("何cmごと:");	scanf("%d", &w);

	for(i=min; i<=max; i+=w){
		printf("%dcm %.2fkg\n", i, (double)(i-100)*0.9);
	}

	return 0;
}
