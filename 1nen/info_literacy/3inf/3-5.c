#include <stdio.h>

int main(){
	int d,bm,bd;
	printf("日数を入力して下さい>");
	scanf("%d",&d);
	if (d<31){
		bm = 1;
		bd = d+1;
	}else{
		if (d<59){
			bm = 2;
			bd = d - 30;
		}else{
			if (d<90){
				bm = 3;
				bd = d - 58;
			}else{
				bm = 4;
				bd = d - 89;
			}
		}
	}
	printf("1月1日の%d日後は%d月%d日です。\n",d,bm,bd);
	return 0;
}
