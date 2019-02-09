#include <stdio.h>

int main(void){
	int x;
	int *p = &x;

	x = 5;
	printf("x : %d\n", x);
	printf("*p: %d\n", *p);

	*p = 100;
	printf("x : %d\n", x);
	printf("*p: %d\n", *p);

	x = x - 50;
	printf("x : %d\n", x);
	printf("*p: %d\n", *p);
	return 0;
}
