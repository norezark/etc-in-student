#include <stdio.h>

int x = 100;

void f1(void){
	int x = 10;
	printf("f1: %d\n", x);
}
void f2(void){
	printf("f2-1: %d\n", x);
	x = x + 10;
	printf("f2-2: %d\n", x);
}
int main(void){
	int x = 5;
	printf("main-1: %d\n", x);
	f1();
	f2();
	f2();
	printf("main-2: %d\n", x);
	return 0;
}
