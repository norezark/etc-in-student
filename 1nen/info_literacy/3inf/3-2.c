#include <stdio.h>

int main(){
	int p,t,tp;
	printf("商品の税抜き価格を入力して下さい>");
	scanf("%d",&p);
	t = p * 0.08;
	tp = p + t;
	printf("税込み価格=%d円\n",tp);
	printf("消費税=%d円\n",t);
	printf("税抜き価格=%d\n",p);
	return 0;
}
