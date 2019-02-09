#include <stdio.h>
#include <limits.h>

int main(void){
	int size;
	size = sizeof(int);
	printf("この処理系ではint型は%dバイトで表現されます。\n", size);
	printf("この処理系でのint型の最大値は%d、最小値は%dです。\n", INT_MAX, INT_MIN);
	
	return 0;
}
