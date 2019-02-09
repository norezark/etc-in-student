#include <stdio.h>

int main(){
		int a, b, c, i, y=0;

		scanf("%d %d %d", &a, &b, &c);

		for(i=a; i<=b; i++){
				if(c%i==0){
						y = y + 1;
				}
		}

		printf("%d\n", y);

		return 0;
}
