#include <stdio.h>
int main(void){
	int i;
	char s1[6];
	printf("Input s1: ");
	scanf("%s", s1);
	for(i=0; i<6; i++)
		printf("s1[%d]: %X\n", i, s1[i]);
	return 0;
}
