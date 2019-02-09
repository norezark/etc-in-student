#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, j, n = 10;
    double h = (1.0-0)/n;

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
        printf("%d\n", i==n-1 ? -1 : 0);
    }

    return 0;
}
