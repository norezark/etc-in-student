#include <stdio.h>
#define STRMAX 256

int mystrlen(char *);

int main(void){
    char str[STRMAX];
    printf("対象文字列: ");
    scanf("%s", str);
    printf("文字列の長さ: %d\n", mystrlen(str));

    return 0;
}

int mystrlen(char *str){
    int t = 0;
    while(*(str+t) != '\0'){
        t++;
    }

    return t;
}
