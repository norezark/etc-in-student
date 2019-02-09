#include <stdio.h>
#include <math.h>

int kaijo(int);

int main(void)
{
    int n;
    printf("n : ");
    scanf("%d", &n);
    if(n < 0) return 1;

    int k;
    double f = 0, x;
    for(x=-1; x<=1; x+=0.1)
    {
        f = 0;
        for(k=0; k<=n; k++)
        {
            f += pow(x, k) / kaijo(k);
        }
        printf("%f\n", f);
    }

    return 0;
}

int kaijo(int n)
{
    if(n > 0)
    {
        return n * kaijo(n-1);
    }
    else
    {
        return 1;
    }
}
