#include <stdio.h>

int main(void){
	int i, j;

	for(i=1; i<=16; i++){
		for(j=1; j<=16; j++)
			printf("%3d ", i*j);
		putchar('\n');
	}

	return 0;
}
