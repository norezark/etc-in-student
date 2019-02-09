#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

void matrixVectorMultiple(double m[N][N], double v[N], double a[N]);
void vectorVectorMultiple(double v1[N], double v2[N], double *a);
void vectorNormalize(double v[N], double a[N]);

int main(void)
{
    int i, j;

    double a[N][N], x[N] = {1}, l0 = 0, e = 1e-5;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf(" %lf", &a[i][j]);
        }
    }

    double lk = l0, lkm1, u[N];
    do
    {
        lkm1 = lk;
        matrixVectorMultiple(a, x, u);
        //for(i=0; i<N; i++) printf("%f ", u[i]);
        //puts("");
        vectorVectorMultiple(x, u, &lk);
        //printf("%f\n", lk);
        vectorNormalize(u, x);
        //for(i=0; i<N; i++) printf("%f ", x[i]);
        //puts("");
    } while(fabs(lk - lkm1) > e);

    printf("lambda = %f\n", lk);
    printf("x = { ");
    for(i=0; i<N; i++)
    {
        printf("%lf ", x[i]);
    }
    puts("}");

    return 0;
}

void matrixVectorMultiple(double m[N][N], double v[N], double a[N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        a[i] = 0;
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            a[j] += m[i][j] * v[i];
        }
    }
}

void vectorVectorMultiple(double v1[N], double v2[N], double *a)
{
    int i;
    *a = 0;
    for(i=0; i<N; i++)
    {
        *a += v1[i] * v2[i];
    }
}

void vectorNormalize(double v[N], double a[N])
{
    double t;
    vectorVectorMultiple(v, v, &t);
    double denominator = sqrt(t);
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = 0;
    }
    for(i=0; i<N; i++)
    {
        a[i] = v[i] / denominator;
    }
}
