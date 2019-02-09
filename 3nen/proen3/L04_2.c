#include <stdio.h>

int main(void){
	char x_char[5];
	int x_int[5];
	double x_double[5];
	
	int i;

	for(i=0; i<5; i++)
		printf("x_char[%d]: %p\n", i, &x_char[i]);
	
	for(i=0; i<5; i++)
		printf("x_int[%d]: %p\n", i, &x_int[i]);

	for(i=0; i<5; i++)
		printf("x_double[%d]: %p\n", i, &x_double[i]);

	return 0;
}
