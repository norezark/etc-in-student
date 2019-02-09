#include <stdio.h>
int main(void){
	int x[] = {5, 10, 15};
	int *p;

	printf("x[0]  : %d\n", x[0]);
	printf("x[1]  : %d\n", x[1]);
	printf("x[2]  : %d\n", x[2]);
	printf("&x[0] : %p\n", &x[0]);
	printf("&x[1] : %p\n", &x[1]);
	printf("&x[2] : %p\n", &x[2]);
	p = x;
	printf("p : %p\n", p);
	printf("p+1 : %p\n", p+1);
	printf("p+2 : %p\n", p+2);
	printf("*p : %d\n", *p);
	printf("*(p+1): %d\n", *(p+1));
	printf("*(p+2): %d\n", *(p+2));
	printf("p[0] : %d\n", p[0]);
	printf("p[1] : %d\n", p[1]);
	printf("p[2] : %d\n", p[2]);
	return 0;
}
