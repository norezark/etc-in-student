#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double f4(double, double);
double func(double x, double y);

int main(void)
{
    srand(time(NULL));
    double a = 1, k, e = 0.0001;
    scanf("%lf", &k);
    double dx, dy, xi = rand()%80-40, xi1, yi = rand()%80-40, yi1;

    while(1)
    {
        dx = (func(xi+a, yi)-func(xi-a, yi))/(2*a);
        dy = (func(xi, yi+a)-func(xi, yi-a))/(2*a);
        xi1 = xi + k * dx;
        yi1 = yi + k * dy;
        printf("%f %f %f\n", xi, yi, func(xi, yi));
        if(sqrt(pow(xi1-xi, 2)+pow(yi1-yi, 2)) <= e) break;
        xi = xi1;
        yi = yi1;
    }

    //printf("%f\n", func(i));
}

double func(double x, double y)
{
    return f4(x, y);
}
