#include <stdio.h>
#include <math.h>

double diffFunc(double, double, double);

int main(void)
{
    double h = 0.4;

    double x = 0, y = 1, z = 1, tz, xmax = 6;
    while(x < xmax)
    {
        printf("%f, %f\n", x, y);
        tz = z;
        z += h * diffFunc(x, y, z);
        y += h * tz;
        x += h;
    }
    printf("%f, %f\n", x, y);

    return 0;
}

double diffFunc(double x, double y, double z)
{
    return exp(x) - y - z;
}
