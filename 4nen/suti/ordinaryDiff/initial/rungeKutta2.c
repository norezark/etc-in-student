#include <stdio.h>

double diffFunc(double, double);

int main(void)
{
    double h = 0.5;

    double x = 1, y = 1, xmax = 20;
    printf("%f, %f\n", x, y);
    while(x <= xmax)
    {
        printf("%f, %f\n", x, y);
        y += h * diffFunc(x + h/2, y + h*diffFunc(x, y)/2);
        x += h;
    }

    return 0;
}

double diffFunc(double x, double y)
{
    return y / (2 * x);
}
