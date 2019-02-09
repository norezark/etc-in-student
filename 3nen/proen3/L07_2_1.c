#include <stdio.h>
#define MAX 10

double fact(int n){
    int i, a = 1;
    for(i=1; i<=n; i++){
        a *= i;
    }
    return a;
}

int main(void){
    int i;
    double s = 1, f;
    for(i=1; (f=fact(i))!=; i++){
        s += 1/f;
    }
    printf("%.10lf\n", s);

    return 0;
}
