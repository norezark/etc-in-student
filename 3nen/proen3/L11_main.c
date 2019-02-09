#include <stdio.h>
#include "L11_head.h"

int x, y;
int main(void){

    printf("x :");
    scanf("%d", &x);
    printf("y :");
    scanf("%d", &y);

    printf("x + y = %d\n", add());

    return 0;
}
