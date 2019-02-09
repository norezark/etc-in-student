#include <stdio.h>

int main(){
	float a,r;
	printf("角度を入力してください>");
	scanf("%f",&a);
	r = a / 180 * 3.141592;
	printf("radianは%fです\n",r);
	return 0;
}
