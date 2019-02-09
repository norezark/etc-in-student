#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void)
{
    //int n = N;
    double c[N][N+1];
    int k, i, j;

    FILE *fp;
    if((fp = fopen("data.txt", "r")) == NULL)
    {
        puts("can't open data.txt");
        exit(1);
    }
    char line[256];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N+1; j++)
        {
            fscanf(fp, "%lf", &c[i][j]);
        }
    }
    fclose(fp);

    double cd;

    for(k=0; k<N; k++)
    {
        for(i=0; i<N; i++)
        {
            if(i != k)
            {
                cd = c[i][k] / c[k][k];
                for(j=k; j<N+1; j++)
                {
                    c[i][j] -= c[k][j] * cd;
                }
            }
        }
    }

    for(i=0; i<N; i++)
    {
        printf("x[%d] = %f\n", i, c[i][N] / c[i][i]);
    }

    return 0;
}
