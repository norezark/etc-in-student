#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, j, n = 10, x0 = 0, y0 = 0, xi = 1, yi = 1;
    double h = (double)(yi-y0)/n, x = x0 + h;

    for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            if(j == i-1)
            {
                printf("%d ", 1);
            }
            else if(j == i)
            {
                printf("%f ", - 2 - h*h);
            }
            else if(j == i+1)
            {
                printf("%d ", 1);
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("%f\n", (i==n-1 ? -1 : 0) + h*h*x);
        x += h;
    }

    return 0;
}
