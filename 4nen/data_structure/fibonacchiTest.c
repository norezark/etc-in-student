#include <stdio.h>
#include <time.h>
#include <math.h>

#define VAR double

VAR fibonacchi1(int n)
{
    if(n > 1)
    {
        return fibonacchi1(n-1) + fibonacchi1(n-2);
    }
    else if(n == 1)
    {
        return 1;
    }

    else if(n == 0)
    {
        return 0;
    }

    return 0;
}

void fibonacchi2(int n)
{
    VAR a = 0;
    VAR b = 1;
    VAR c;
    int i = 1;
    while(i < n)
    {
        //printf("%d: %lf\n", i, a);
        i++;
        c = a;
        a += b;
        b = c;
    }
}

int main(void)
{
    int i, j;
    int inc = 5;

    for(i=0; i <= 1476; i+=inc)
    {
        clock_t before;
        double elapsed;

        before = (double)clock();

        VAR a = 0;
        VAR b = 1;
        VAR c = a;
        for(j=0; j<=i; j++)
        {
            c = a;
            a += b;
            b = c;
        }

        elapsed = ((double)clock() - before) / CLOCKS_PER_SEC;

        printf("%d,%f\n", i, elapsed);
    }

    return 0;
}
