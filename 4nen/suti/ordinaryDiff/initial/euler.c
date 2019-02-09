#include <stdio.h>

double diffFunc(double, double);

int main(void)
{
    double h = 0.1;

    double x = 0, y = 1, xmax = 2.5;
    while(x < xmax)
    {
        printf("%f %f\n", x, y);
        y += h * diffFunc(x, y);
        x += h;
    }
    printf("%f %f\n", x, y);

    return 0;
}

double diffFunc(double x, double y)
{
    return x * y;
}
