#include <stdio.h>

int main(void){
    double data[5] = {10, 34, 56, 32, 9};
    int i;

    printf("変数iのアドレス:%X 変数iの値:%d\n", &i, i);

    printf("アドレス:データ\n");
    for(i=0; i<5; i++){
        printf("%X:%5f\n", &data[i], data[i]);
    }

    printf("変数iのアドレス:%X 変数iの値:%d\n", &i, i);

    return 0;
}
