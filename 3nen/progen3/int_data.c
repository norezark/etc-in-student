#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fpr, *fpw;
    int buf[10000], add_data;
    int i, size;

    fpr = fopen("int.data", "rb");
    if(fpr == NULL){
        printf("%sファイルが開きません\n", "int.data");
        exit(1);
    }
    size = fread(buf, sizeof(int), 10000, fpr);
    fclose(fpr);

    printf("元のファイルのデータ個数:%d\n", size);
    for(i=0; i<size; i++){
        printf("%d: %d\n", i, buf[i]);
    }

    printf("追加するデータを入力:");
    scanf("%d", &add_data);
    buf[size] = add_data;

    fpw = fopen("int.data", "wb");
    if(fpw == NULL){
        printf("%sファイルが開けません\n", "int.data");
        exit(1);
    }
    fwrite(buf, sizeof(int), size+1, fpw);
    fclose(fpw);

    return 0;
}
