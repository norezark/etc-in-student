#include <stdio.h>

int main(){
		int x, y, tmp;

		while(1){
				scanf("%d %d", &x, &y);

				if(x==0 && y==0) break;

				if(x>y){
						tmp = x;
						x = y;
						y = tmp;
				}

				printf("%d %d\n", x, y);
		}

		return 0;
}
