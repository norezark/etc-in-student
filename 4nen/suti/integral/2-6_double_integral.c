#include <stdio.h>
#include <math.h>

double func(double, double);

int main(void)
{
    int n, m;
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);
    double v=0, x, y, a = 0, b = 10, c = 0, d = 20, hx = (b-a)/n, hy = (d-c)/m;

    for(x=a; x < b; x += hx)
    {
        for(y=c; y < d; y += hy)
        {
            v += func(x, y) * hx * hy;
        }
    }

    printf("ans = %f\n", v);

    return 0;
}

double func(double x, double y)
{
    return x*x * y*y;
}
