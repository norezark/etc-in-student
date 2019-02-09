#include <stdio.h>

int main(){
		int w, h, x, y, r;

		scanf("%d %d %d %d %d", &w, &h, &x, &y, &r);

		if (x+r>w || x-r<0 || y+r>h || y-r<0){
				puts("No");
		}else{
				puts("Yes");
		}

		return 0;
}
