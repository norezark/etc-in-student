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
        i += h * diffFunc(t, i);
        t += h;
    }
    printf("%f, %f\n", t, i);

    return 0;
}

double diffFunc(double t, double i)
{
    return (E - RL * i) / L;
}
