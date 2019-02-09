#include <stdio.h>
#include <math.h>

double diffFunc1(double x, double y, double z);
double diffFunc2(double x, double y, double z);

int main(void)
{
    double h = 0.5;

    double x = 0, y = 1, z = 1, xmax = 5;
    while(x < xmax)
    {
        printf("%f, %f\n", x, y);
        double ky1 = h * diffFunc1(x, y, z);
        double kz1 = h * diffFunc2(x, y, z);
        double ky2 = h * diffFunc1(x + h/2, y + ky1/2, z + kz1/2);
        double kz2 = h * diffFunc2(x + h/2, y + ky1/2, z + kz1/2);
        y += ky2;
        z += kz2;
        x += h;
    }
    printf("%f, %f\n", x, y);

    return 0;
}

double diffFunc1(double x, double y, double z)
{
    return z;
}

double diffFunc2(double x, double y, double z)
{
    return exp(x) - y - z;
}
