#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int r1, r2, a, i=0;

	do{
		i++;
		srand((unsigned)time(NULL));
		r1 = rand()%90 + 10;
		r2 = rand()%90 + 10;
		printf("%d + %d :", r1, r2);	scanf("%d",&a);
	}while(a==r1+r2);

	printf("残念！正解は%dでした。\n計%d問正解です。\n", r1+r2, i-1);

	return 0;
}
