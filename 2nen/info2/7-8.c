#include <stdio.h>
int getmul3num(int v[], int len){
	int i, sum;
	for(i=0; i<len; i++)
		if(v[i]%3==0)	sum++;
	return sum;
}
int main(void){
	int x[6] = {1, 2, 3, 4, 5, 6};
	printf("3の倍数の値は%d個含まれています。\n", getmul3num(x, 6));
	return 0;
}
