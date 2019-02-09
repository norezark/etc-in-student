#include <stdio.h>

int main(){
	double r1,r2,rs,rp;
	printf("抵抗値を入力して下さい（その1）>");
	scanf("%lf",&r1);
	printf("抵抗値を入力して下さい（その2）>");
	scanf("%lf",&r2);
	rs = r1 + r2;
	rp = (r1 * r2) / r1 + r2;
	printf("直列接続したときの抵抗値は%lfです。\n",rs);
	printf("並列接続したときの抵抗値は%lfです。\n",rp);
	return 0;
}
