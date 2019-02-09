#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct t{
    double x;
    struct t *next;
} Data;

void parse(char []);
double tod(char [], int *);
void push(double);
double pop();

Data *top;

int main(void){
    char s[256];
    while(1){
        printf("数式: ");
        if((fgets(s, 256, stdin) == NULL)){
            puts("exit");
            break;
        }
        parse(s);
    }

    return 0;
}

void parse(char s[]){
    int i = 0;
    double a, b;
    top = NULL;
    while(s[i] != '\n' && s[i] != '\0'){
        while(s[i] == ' ') i++;
        if(s[i]=='-' && isdigit(s[i+1])){
            i++;
            push(-tod(s, &i));
        }else if(isdigit(s[i])){
            push(tod(s, &i));
        }else{
            a = pop();
            b = pop();
            switch(s[i]){
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
                case '%':
                    push(fmod(b, a));
                    break;
                case '^':
                    push(powl(b, a));
                    break;

                default:
                    puts("使用できない文字");
                    while(top != NULL) pop();
                    return;
            }
        }
        i++;
    }

    printf("%g\n", pop());
}

double tod(char s[], int *i){
    int u = 10;
    double p = 1, t = 0;
    while(1){
        if(isdigit(s[*i])){
            t = t * u + (s[*i] - '0') * p;
            if(p <= 0.1) p /= 10;
        }else if(s[*i] == '.'){
            p = 0.1;
            u = 1;
        }else{
            (*i)--;
            break;
        }
        (*i)++;
    }
    return t;
}

void push(double t){
    Data *tmp;
    if((tmp = (Data *)calloc(1, sizeof(Data))) == NULL){
        puts("alloc error");
        exit(1);
    }

    tmp->next = top;
    top = tmp;
    top->x = t;
}

double pop(){
    if(top == NULL) exit(1);
    double t = top->x;
    Data *tmp = top->next;
    free(top);
    top = tmp;
    return t;
}
