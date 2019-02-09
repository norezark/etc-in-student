#include <stdio.h>

int main(){
	double s,t,h;
	printf("身長を入力して下さい>");
	scanf("%lf",&s);
	printf("体重を入力して下さい>");
	scanf("%lf",&t);
	h = s * s * 22;
	if (h > t){
		printf("あなたは標準体重の%fkgより%fkg痩せています\n",h,h-t);
	}else{
		printf("あなたは標準体重の%fkgより%fkg太っています\n",h,t-h);
	}
	return 0;
}
