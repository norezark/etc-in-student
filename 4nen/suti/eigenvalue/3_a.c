#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 2

void powerMethod(double a[N][N], double l0, double e, double *ln, double un[N]);
void vectorSetRandom(double v[N]);
void matrixVectorMultiple(double m[N][N], double v[N], double a[N]);
void matrixScalarMultiple(double m[N][N], double s, double a[N][N]);
void vectorVectorDotProduct(double v1[N], double v2[N], double *a);
void vectorVectorCrossProduct(double v1[N], double v2[N], double a[N][N]);
void vectorNormalize(double v[N], double a[N]);
void matrixMatrixMinor(double m1[N][N], double m2[N][N], double a[N][N]);
void printVector(double v[N]);
void printMatrix(double m[N][N]);

int main(void)
{
    srand((unsigned int)time(NULL));
    int i, j;

    double a[N][N], l0 = 0, e = 1e-9, l, u[N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf(" %lf", &a[i][j]);
        }
    }

    powerMethod(a, l0, e, &l, u);

    double b[N][N], t[N][N];
    vectorVectorCrossProduct(u, u, t);
    matrixScalarMultiple(t, l, t);
    matrixMatrixMinor(a, t, b);

    powerMethod(b, l0, e, &l, u);

    return 0;
}

void powerMethod(double a[N][N], double l0, double e, double *ln, double un[N])
{
    int i;
    double x[N];
    vectorSetRandom(x);
    vectorNormalize(x, x);
    double lk = l0, lkm1 = l0+e, u[N];
    do
    {
        lkm1 = lk;
        matrixVectorMultiple(a, x, u);
        vectorVectorDotProduct(x, u, &lk);
        vectorNormalize(u, x);
    } while(fabs(lk - lkm1) > e);

    *ln = lk;
    memcpy(un, x, sizeof(x[0]) * N);

    printf("lambda = %f\n", *ln);
    printf("x = ");
    printVector(un);
}

void vectorSetRandom(double v[N])
{
    int i;
    for(i=0; i<N; i++)
    {
        v[i] = rand();
    }
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

void matrixScalarMultiple(double m[N][N], double s, double a[N][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            a[i][j] = m[i][j] * s;
        }
    }
}

void vectorVectorDotProduct(double v1[N], double v2[N], double *a)
{
    int i;
    *a = 0;
    for(i=0; i<N; i++)
    {
        *a += v1[i] * v2[i];
    }
}

void vectorVectorCrossProduct(double v1[N], double v2[N], double a[N][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            a[i][j] = v1[j] * v2[i];
        }
    }
}

void vectorNormalize(double v[N], double a[N])
{
    double t;
    vectorVectorDotProduct(v, v, &t);
    double denominator = sqrt(t);
    int i;
    for(i=0; i<N; i++)
    {
        a[i] = v[i] / denominator;
    }
}

void matrixMatrixMinor(double m1[N][N], double m2[N][N], double a[N][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            a[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void printVector(double v[N])
{
    int i;
    printf("{ ");
    for(i=0; i<N; i++)
    {
        printf("%.3f ", v[i]);
    }
    puts("}");
}

void printMatrix(double m[N][N])
{
    int i;
    puts("{");
    for(i=0; i<N; i++)
    {
        putchar('\t');
        printVector(m[i]);
    }
    puts("}");
}
