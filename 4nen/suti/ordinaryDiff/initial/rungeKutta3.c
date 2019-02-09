#include <stdio.h>

double diffFunc(double, double);

int main(void)
{
    double h = 0.5;

    double x = 1, y = 1, xmax = 20, k1, k2, k3;
    printf("%f, %f\n", x, y);
    while(x <= xmax)
    {
        printf("%f, %f\n", x, y);
        k1 = h * diffFunc(x, y);
        k2 = h * diffFunc(x + h/2, y + h/2);
        k3 = h * diffFunc(x + h, y + 2 * k2 - k1);
        y += (k1 + 4 * k2 + k3) / 6;
        x += h;
    }

    return 0;
}

double diffFunc(double x, double y)
{
    return y / (2 * x);
}
