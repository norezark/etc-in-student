#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 12

void show(double c[N][N*2]);

int main(void)
{
    int n=N, k, i, j;
    double c[N][N*2];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N*2; j++)
        {
            if(j-N == i)
            {
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = 0;
            }
        }
    }
    double b[N];

    FILE *fp;
    if((fp = fopen("data2.txt", "r")) == NULL)
    {
        puts("can't read data.txt");
        exit(1);
    }
    char line[256];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            fscanf(fp, "%lf", &c[i][j]);
        }
        fscanf(fp, "%lf", &b[i]);
    }
    fclose(fp);

    double cd, tm, t[N*2];
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
        for(j=0; j<n * 2; j++)
        {
            c[k][j] /= cd;
        }
        for(i=0; i<n; i++)
        {
            if(i != k)
            {
                cd = c[i][k];
                for(j=k; j<n * 2; j++)
                {
                    c[i][j] -= c[k][j] * cd;
                }
            }
        }
    }

    double x[N] = {0};
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            x[i] += c[i][n+j] * b[j];
        }
    }

    for(i=0; i<n; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }
}

void show(double c[N][N*2])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N*2; j++)
        {
            printf("%.2f ", c[i][j]);
        }
        puts("");
    }
}
