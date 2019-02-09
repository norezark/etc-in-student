#include <stdio.h>

int main(void){
	int n, i;

	printf("nの値:"); scanf("%d", &n);

	for(i=1; i<=n; i++){
		printf("%dの2乗は%d\n", i, i*i);
	}

	return 0;
}
