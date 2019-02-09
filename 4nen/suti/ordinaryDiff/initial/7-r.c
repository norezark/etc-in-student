#include <stdio.h>

#define E 100
#define RL 15
#define RS 10
#define L (500 * 0.001)

double diffFunc(double, double);

int main(void)
{
    double h = 0.01;

    double t = 0, i = E / RS, tmax = 0.3;
    while(t < tmax)
    {
        printf("%f, %f\n", t, i);
        double k1 = h * diffFunc(t, i);
        double k2 = h * diffFunc(t + h/2, i + h/2);
        double k3 = h * diffFunc(t + h/2, i + k2/2);
        double k4 = h * diffFunc(t + h, i + k3);
        i += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t += h;
    }
    printf("%f, %f\n", t, i);

    return 0;
}

double diffFunc(double t, double i)
{
    return (E - RL * i) / L;
}
