#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 3

int main(void){
    int n = N, m = 0, i, j, k = 0;
    int a[N][N], b[N], t[N];
    double x[N] = {0}, s, e = 0.0001, o = 1.2;

    FILE *fp;
    if((fp = fopen("data.txt", "r")) == NULL)
    {
        puts("can't read data.txt");
        exit(1);
    }
    char line[256];
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n; j++)
        {
            fscanf(fp, "%d", j!=n?&a[i][j]:&b[i]);
        }
    }
    fclose(fp);

    double tx;
    while(m != n){

        k++;
        m = 0;
        for(i=0; i<n; i++){
            s = 0;
            for(j=0; j<n; j++){
                s += a[i][j] * x[j];
            }
            tx = (b[i] - s) / a[i][i] + x[i];
            tx = x[i] + o * (tx - x[i]);
            if(fabs((tx - x[i])/tx) < e) m++;
            x[i] = tx;
        }
    }

    for(i=0; i<n; i++){
        printf("x%d = %f\n", i+1, x[i]);
    }
    printf("e = %f, k = %d, o = %f\n", e, k, o);

    return 0;
}
