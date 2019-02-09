#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[30];
    int age;
} Person;

int main(void){
    FILE *fpr, *fpw;
    Person buf[10000], add_data;
    int i, size;

    fpr = fopen("struct.data", "rb");
    if(fpr == NULL){
        printf("%sファイルが開けません\n", "struct.data");
        exit(1);
    }
    size = fread(buf, sizeof(Person), 10000, fpr);
    fclose(fpr);

    printf("元のファイルデータ個数:%d\n", size);
    for(i=0; i<size; i++){
        printf("%d:|%s|%d|\n", i, buf[i].name, buf[i].age);
    }
    printf("\n");

    printf("追加するデータを入力:\n名前->");
    fgets(add_data.name, 30, stdin);
    if(add_data.name[strlen(add_data.name)-1] == '\n')
        add_data.name[strlen(add_data.name)-1] = '\0';

    printf("年齢->");
    scanf("%d", &add_data.age);
    buf[i] = add_data;
    printf("|%s|%d|\n", add_data.name, add_data.age);

    fpw = fopen("struct.data", "wb");
    if(fpw == NULL){
        printf("%sファイルが開けません\n", "struct.data");
        exit(1);
    }
    fwrite(buf, sizeof(Person), size+1, fpw);
    fclose(fpw);

    return 0;
}
