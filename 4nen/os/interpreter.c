#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char func;
    int addr;
} instruction;

void interpret(instruction code[], int *pc, char fileName[]);
int execute(instruction ir, int *acc, int *data, int *pc);

int main(int argc, char *argv[])
{
    instruction ir;
    int pc = 0;
    int acc;
    instruction code[1024];
    int dataArray[1024];
    int *data = dataArray;

    if(argc == 2)
    {
        interpret(code, &pc, argv[1]);
    }
    else
    {
        printf("bad argument.\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        ir = code[pc];
        pc++;
        if(execute(ir, &acc, data, &pc)) break;
    }

    return 0;
}

void interpret(instruction code[], int *pc, char fileName[])
{
    FILE *fp;
    char s[256];

    if((fp = fopen(fileName, "r")) == NULL)
    {
        printf("can't open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    instruction t;
    if(fscanf(fp, " %c %d", &t.func, &t.addr) != EOF)
    {
        if(t.func == '*') i = t.addr;
    }
    else
    {
        printf("bad context\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    while(fscanf(fp, " %c %d", &code[i].func, &code[i].addr) != EOF)
    {
        if(code[i].func == '/')
        {
            *pc = code[i].addr;
            break;
        }
        //printf("[%d] %c: %d\n", i, code[i].func, code[i].addr);
        i++;
    }

    fclose(fp);
}

int execute(instruction ir, int *acc, int *data, int *pc)
{
    switch(ir.func)
    {
        case 'L':
            *acc = data[ir.addr];
            break;
        case 'C':
            *acc = ir.addr;
            break;
        case 'T':
            data[ir.addr] = *acc;
            break;
        case 'A':
            *acc += data[ir.addr];
            break;
        case 'S':
            *acc -= data[ir.addr];
            break;
        case 'M':
            *acc *= data[ir.addr];
            break;
        case 'D':
            *acc /= data[ir.addr];
            break;
        case 'J':
            *pc = ir.addr;
            break;
        case 'Z':
            if(*acc == 0) *pc = ir.addr;
            break;
        case 'R':
            scanf(" %d", &data[ir.addr]);
            break;
        case 'W':
            printf("%d\n", data[ir.addr]);
            break;
        case 'H':
            return 1;
            break;
        default:
            return -1;
            break;
    }

    return 0;
}
