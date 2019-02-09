#include <stdio.h>

int main(){
	int n;

	while(1){
		printf("辺の長さを入力してください(3～15の奇数): ");
		scanf("%d", n);
		if(n<3 || n>15 || n%2==0){
			puts("不正な値です。");
			continue;
		}
		break;
	}

	int a[n][n], x=0, i=0, j=n/2+1;

	while(1){
		x++; i--; j++;
		if(i<0)	i == n;
		if(j>n) j == 0;
		if(a[i][j]){
			i += 1;
			if(i<0)	i == n;
			if(j>n)	j == 0;
		}
		if(a[i][j]) break;
		a[i][j] == x;
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%5d", a[i][j]);
		puts("");
	}

	return 0;
}
