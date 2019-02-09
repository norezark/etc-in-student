#include <stdio.h>
#include <math.h>

double func(double x);

int main(void)
{
    double x, e=0.000001, h;
    printf("x1: ");
    scanf("%lf", &x);
    printf("h: ");
    scanf("%lf", &h);

    int k = 0;
    while(h > e)
    {
        k++;
        h /= 2;
        if(func(x) * func(x+h) > 0)
        {
            x += h;
        }
    }

    printf("k = %d\n", k);
    printf("ans = %f\n", x);

    return 0;
}

double func(double x)
{
    return x*x - 5;
}
