#include <stdio.h>

int main(){
	int ss,h,m,s;
	printf("時間(単位は秒)を入力して下さい>");
	scanf("%d",&ss);
	h = ss / 3600;
	m = (ss - (h*3600)) / 60;
	s = ss - (h*3600) - (m*60);
	printf("%d秒は%d時間%d分%d秒です。\n",ss,h,m,s);
	return 0;
}
