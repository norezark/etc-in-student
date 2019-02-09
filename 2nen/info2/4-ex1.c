#include <stdio.h>

int main(void){
	int h, w, i, j;

	printf("高さ:");	scanf("%d", &h);
	printf("横幅:");	scanf("%d", &w);

	for(i=1; i<=h; i++){
		for(j=1; j<=w; j++){
			if(i!=1 && i!=h && j!=1 && j!=w){
				putchar(' ');
			}else{
				putchar('*');
			}
		}
		putchar(' ');
		puts("");
	}

	return 0;
}
