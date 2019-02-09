#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n, k, i, j;
    scanf(" %d", &n);

    double **c;
    c = (double **)calloc(n, sizeof *c);
    if(c == NULL)
    {
        puts("メモリ確保に失敗");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<n; i++)
    {
        c[i] = (double *)calloc(n+1, sizeof *c[i]);
        if(c[i] == NULL)
        {
            puts("メモリ確保に失敗");
            exit(EXIT_FAILURE);
        }
    }

    double *t;
    t = (double *)calloc(n+1, sizeof *t);
    if(t == NULL)
    {
        puts("メモリ確保に失敗");
        exit(EXIT_FAILURE);
    }

    double cd, tm;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
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
                memcpy(t, c[k], sizeof(t[0])*(n+1));
                memcpy(c[k], c[i], sizeof(t[0])*(n+1));
                memcpy(c[i], t, sizeof(t[0])*(n+1));
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

    for(i=0; i<n; i++)
    {
        free(c[i]);
    }
    free(c);
    free(t);

    return 0;
}
