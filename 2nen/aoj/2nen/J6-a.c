#include <stdio.h>

int main(void){
	int i, n , a[1000];

	scanf("%d", &n);
	scanf("%s", a);
	
	for(i=0; i<n; i++){
		if(i)	printf(" ");
		printf("%d", a[n-i-1]);
	}
	return 0;
}
