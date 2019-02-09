#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 5

int main(void)
{
    gauss-jordan-normalize();
    return 0;
}


void gauss-jordan-normalize()
{
    double c[N][N+1];

    int k, i, j, n = N;
    double cd, t[N+1], tm;
    FILE *fp;
    if((fp = fopen("data.txt", "r")) == NULL)
    {
        puts("can't open data.txt");
        exit(1);
    }
    char line[256];
    for(i=0; i<N; i++)
    {
        for(j=0; j<=N; j++)
        {
            fscanf(fp, "%lf", &c[i][j]);
        }
    }
    fclose(fp);

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
                puts("ピボット入れ替えを実行");
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
        printf("x[%d] = %f\n", i, c[i][n]);
    }

}
