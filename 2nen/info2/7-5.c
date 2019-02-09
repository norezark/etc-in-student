#include <stdio.h>

void greeting(int n){
	switch(n){
		case 1:
			puts("Good morning.");
			break;
		case 2:
			puts("Good afternoon.");
			break;
		case 3:
			puts("Good evening.");
			break;
		default:
			puts("Hi.");
			break;
	}
}

int main(void){
	int x;
	printf("朝(1), 昼(2), 夕方(3)のどれかを選んでください: ");
	scanf("%d", &x);
	greeting(x);

	return 0;
}
