#include  <stdio.h>

char       x_char;
int          x_int;
double   x_double;

int   main(void)
{
		char      y_char;
		int         y_int;
		double  y_double;

		printf("x_char:   size=%d    address=%p\n", sizeof(x_char), &x_char);
		printf("x_int:   size=%d    address=%p\n", sizeof(x_int), &x_int);
		printf("x_double:   size=%d    address=%p\n", sizeof(x_double), &x_double);
		printf("y_char:   size=%d    address=%p\n", sizeof(y_char), &y_char);
		printf("y_int:   size=%d    address=%p\n", sizeof(y_int), &y_int);
		printf("y_double:   size=%d    address=%p\n", sizeof(y_double), &y_double);


		return 0;
}
