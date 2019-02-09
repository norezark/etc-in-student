#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double f2(double x);
double func(double x);

int main(void)
{
    srand(time(NULL));
    double a = 1, k = 1000, e = 0.001;
    double delta, xi = rand()%abs(130-(-70))+(-70), xi1;

    while(1)
    {
        delta = (func(xi+a)-func(xi-a))/(2*a);
        xi1 = xi + k * delta;
        printf("%f %f\n", xi, func(xi));
        if(fabs(xi1-xi) <= e) break;
        xi = xi1;
    }

    //printf("%f\n", func(i));
}

double func(double x)
{
    return f2(x);
}
