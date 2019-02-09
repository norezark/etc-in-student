#include <stdio.h>
int getloc(int v[], int len, int val){
	int i;
	for(i=len-1; i>=0; i--)
		if(v[i]==val)	break;
	return i;
}
int main(void){
	int x[5] = {1, 3, 5, 7, 9};
	int num, a;
	printf("探す値は?: ");
	scanf("%d", &num);
	a = getloc(x, 5, num);
	if(a>=0)
		printf("%dは%d番目の要素にあります。\n", num, a);
	else
		puts("見つかりませんでした。");
	return 0;
}
