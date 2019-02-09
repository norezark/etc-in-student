#include <stdio.h>
#include <math.h>
#define E 1.0
#define R 1095.0
#define L 0.3
#define C 1 * pow(10, -6)

double func(double x);

int main(void)
{
    double x, e=1*pow(10, -9), h;
    printf("x1: ");
    scanf("%lf", &x);
    printf("h: ");
    scanf("%lf", &h);

    int k = 0;
    while(fabs(h) > e)
    {
        k++;
        h /= 2;
        if(func(x) * func(x+h) > 0)
        {
            x += h;
        }
    }

    printf("k1 = %d\n", k);
    printf("ans1 = %e\n", x);

    printf("x1: ");
    scanf("%lf", &x);
    printf("h: ");
    scanf("%lf", &h);

    k = 0;
    while(fabs(h) > e)
    {
        k++;
        h /= 2;
        if(func(x) * func(x+h) > 0)
        {
            x += h;
        }
    }

    printf("k2 = %d\n", k);
    printf("ans2 = %e\n", x);

    return 0;
}

double func(double x)
{
    return x*exp(-R*x/(2*L))*E/L - E/(M_E*R);
}
