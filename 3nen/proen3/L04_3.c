#include  <stdio.h>

int  main(void)
{
		const  int   a = 10;
		const  int   b = 20;
		int *pa, *pb;

		pa = &a;
		pb = &b;

		int *tmp;
		tmp = pa;
		pa = pb;
		pb = tmp;

		printf("*pa = %d\n", *pa);
		printf("*pb = %d\n", *pb);

		return 0;
}
