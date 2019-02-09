#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    double y;
    double r;
    int i;

    srandom(time(NULL));

    for(i=0; i<44100*2; i++){
        r = random();
        y = 15000.0 / RAND_MAX * (r - RAND_MAX / 2.0);
        printf("%d\n%d\n", (short)y, (short)y);
    }

    return 0;
}
