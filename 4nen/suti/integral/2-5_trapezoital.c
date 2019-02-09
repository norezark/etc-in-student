#include <stdio.h>
#include <math.h>

double func(double);

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    double s=0, x, a = 0, b = 1, h = (b-a)/n;

    for(x=0; x < b; x += h)
    {
        s += (func(x) + func(x+h)) * h/2;
    }

    printf("ans = %f\n", s);

    return 0;
}

double func(double x)
{
    return 4 / (1 + x*x);
}
