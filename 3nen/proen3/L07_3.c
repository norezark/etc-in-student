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
    double s = 0;
    scanf("%d", &n);
    for(i=n; i>0; i--){
        s += 1/fact(i);
    }
    s += 1;
    printf("e   = %.30f\nM_E = %.30f\n", s, M_E);

    return 0;
}
