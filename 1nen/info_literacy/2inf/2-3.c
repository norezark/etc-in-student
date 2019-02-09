#include <stdio.h>

int main(){
	int hour,minute,second,secondS;
	printf("時間を入力してください>");
	scanf("%d",&hour);
	printf("分を入力してください>");
	scanf("%d",&minute);
	printf("秒を入力して下さい>");
	scanf("%d",&second);
	secondS = hour*3600 + minute*60 + second;
	printf("%d時間%d分%d秒は %d 秒です。\n",hour,minute,second,secondS);
	return 0;
}
