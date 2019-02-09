#include <stdio.h>

int main(void)
{
	int p,t,s;
	printf("クラスの人数を入力して下さい>");
	scanf("%d",&p);
	t = p / 9;
	s = p % 9;
	printf("そのクラスでは野球チームを%dチーム作れます。\n",t);
	printf("また%d人余ります。\n",s);
	return 0;
}
