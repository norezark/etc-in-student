#include <stdio.h>
#include <math.h>

double func(double);

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    double s=0, x, a = 0, b = 1, h = (b-a)/n;

    for(x=0; x < b; x += 2*h)
    {
        s += (func(x) + 4*func(x+h) + func(x+2*h)) * h/3;
    }

    printf("ans = %f\n", s);

    return 0;
}

double func(double x)
{
    return 4 / (1 + x*x);
}
