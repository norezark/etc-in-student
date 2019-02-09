#include <stdio.h>

int main(void){
	int x;
	while(1){
		scanf("%d", &x);

		if(x<1 || x>9){
			puts("もう一度入力してください");
			continue;
		}
		break;
	}

	puts("OK");

	return 0;
}
