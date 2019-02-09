#include <stdio.h>
#include <math.h>

double func(double x);
double func_diff(double x);

int main(void)
{
    double x = 1, e = 0.00001;
    double slope;

    int k = 0;
    while(1)
    {
        k++;
        slope = func(x) / func_diff(x);
        if(fabs(slope/x) < e)
        {
            break;
        }
        else
        {
            x -= slope;
        }
    }

    printf("k = %d\n", k);
    printf("ans = %f\n", x);

    return 0;
}

double func(double x)
{
    return x*x - 5;
}

double func_diff(double x)
{
    return 2*x;
}
