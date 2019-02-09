#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 9

int main(void)
{
    double c[N][N+1];

    int k, i, j, n = N;
    double cd, t[N+1], tm;
    for(i=0; i<N; i++)
    {
        for(j=0; j<=N; j++)
        {
            scanf("%lf", &c[i][j]);
        }
    }

    for(k=0; k<n; k++)
    {
        tm = c[k][k];

        for(i=k+1; i<n; i++)
        {
            if(fabs(c[i][k]) > tm)
            {
                tm = c[i][k];
                memcpy(t, c[k], sizeof(t));
                memcpy(c[k], c[i], sizeof(t));
                memcpy(c[i], t, sizeof(t));
            }
        }

        cd = c[k][k];

        for(j=0; j<=n; j++)
        {
            c[k][j] = c[k][j] / cd;
        }
        for(i=0; i<n; i++)
        {
            if(i != k)
            {
                cd = c[i][k];
                for(j=k; j<=n; j++)
                {
                    c[i][j] = c[i][j] - c[k][j] * cd;
                }
            }
        }
    }

    for(i=0; i<n; i++)
    {
        printf("%f\n", c[i][n]);
    }

    return 0;
}
