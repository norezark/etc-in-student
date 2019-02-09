#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int kaijo(int);
double bibun(int);

int main(void)
{
    int n;
    printf("n : ");
    scanf("%d", &n);
    if(n < 0) exit(1);

    int k;
    double f, x;
    for(x=-1; x<=1; x+=0.1)
    {
        f = 0;
        for(k=0; k<=n; k++)
        {
            f += (bibun(k) / kaijo(k)) * pow(x, k);
        }
        printf("%f\n", f);
    }

    return 0;
}

int kaijo(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return n * kaijo(n-1);
}

double bibun(int k)
{
    if(k == 0)
    {
        return log(2);
    }
    else
    {
        return (pow(-1, k-1) * kaijo(k-1)) / pow(2, k);
    }
}
