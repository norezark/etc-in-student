#include <stdio.h>

int main(){
	int tp,t,p;
	printf("商品の税込み価格を入力して下さい>");
	scanf("%d",&tp);
	p = tp / 1.08;
	t = tp - p;
	printf("税込み価格=%d円\n",tp);
	printf("消費税=%d円\n",t);
	printf("税抜き価格=%d円\n",p);
	return 0;
}
