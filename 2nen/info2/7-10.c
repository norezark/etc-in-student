#include <stdio.h>
void show(int v[], int len){
	int i;
	for(i=0; i<len; i++)
		printf("%d\n", v[i]);
}
void clear(int v[], int len, int val){
	int i;
	for(i=0; i<len; i++)
		v[i] = val;
}
int main(void){
	int x[5] = {1, 30, -5, 2, 5000};
	puts("(初期状態)");
	show(x, 5);
	clear(x, 5, 100);
	puts("(claer関数を呼出した後)");
	show(x, 5);
	return 0;
}
