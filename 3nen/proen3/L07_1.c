#include <stdio.h>

double fact(int n){
    int i;
    double s = 1;
    for(i=1; i<=n; i++){
        s *= i;
    }
    return s;
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%e\n", fact(n));

    return 0;
}
