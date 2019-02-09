#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double func(double x);

int main(void)
{
    srand(time(NULL));
    double a = 0.1, k = 0.1, e = 0.01;
    double delta, xi = rand()%10+5, xi1;

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
    return 20 - pow(x - 10, 2);
}
