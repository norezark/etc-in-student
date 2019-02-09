#include <stdio.h>
#define STRMAX 256

int f2(char *);

int main(void){
    char str[STRMAX];
    printf("対象文字列: ");
    scanf("%s", str);
    printf("文字列->数値: %d\n", f2(str));

    return 0;
}

int f2(char *str){
    int t = 0;
    while(*str != '\0'){
        t = t * 10 + *str++ - '0';
    }

    return t;
}
