#include <stdio.h>
#include <math.h>

double fact(int n){
    int i;
    double a = 1;
    for(i=1; i<=n; i++){
        a *= i;
    }
    return a;
}

int main(void){
    int i, n;
    double s = 1;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        s += 1/fact(i);
    }
    printf("e   = %.30f\nM_E = %.30f\n", s, M_E);

    return 0;
}
