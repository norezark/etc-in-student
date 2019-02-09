#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    int n;
    int *x;

    printf("Input array size:");
    scanf("%d", &n);

    x = (int *)calloc(n, sizeof(int));

    if(x == NULL){
        fprintf(stderr, "ERROR: malloc\n");
        return 1;
    }

    for(i=0; i<n; i++){
        x[i] = i * i;
        printf("x[%d] = %d\n", i, x[i]);
    }

    for(i=n-1; i>=0; i--){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}
