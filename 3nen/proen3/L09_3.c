#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define KYOUKA 2
#define LINE_MAX 256

int students;
int **tensu;

void InputData(char *fname);
double mean(int ninzu, int ktensu[]);
double corr(int ninzu, int xTensu[], int yTensu[]);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage:%s [filename]\n", argv[0]);

        return 1;
    }

    InputData(argv[1]);
    
    int k1, k2;
    for(k1=0; k1<=KYOUKA; k1++){
        for(k2=0; k2<=KYOUKA; k2++){
            if(k1 == 0 && k2 != 0){
                printf("%d\t", k2-1);
            }else{
                if(k1 <= k2){
                    printf("-\t");
                }else{
                    if(k2 == 0){
                        printf("%d\t", k1-1);
                    }else{
                        printf("%.3f\t", corr(students, tensu[k1-1], tensu[k2-1]));
                    }
                }
            }
        }
        puts("");
    }

    int i, j;
    for(i=0; i<KYOUKA; i++){
       free(tensu[i]);
    }
    free(tensu);
    return 0;
}

void InputData(char *fname){
    FILE *fp;
    char t[LINE_MAX];
    char st[LINE_MAX];
    int f = 0, tmp, i, j;

    if((fp = fopen(fname, "r")) == NULL){
        printf("ファイルが開けません。");
    }else{
        fscanf(fp, "%d", &students);
        tensu = calloc(KYOUKA, sizeof(int)*students);
        for(j=0; j<KYOUKA; j++){
            tensu[j] = calloc(students, sizeof(int));
        }
        for(i=0; i<students; i++){
            for(j=0; j<KYOUKA; j++){
                fscanf(fp, "%d", &tensu[j][i]);
            }
        }
    }       
}

double mean(int ninzu, int ktensu[]){
    int i;
    double s = 0;
    for(i=0; i<ninzu; i++){
        s += ktensu[i];
    }
    return s/ninzu;
}

double corr(int ninzu, int xTensu[], int yTensu[]){
    double t1 = 0, t2 = 0, t3 = 0, x, y;
    int i;

    for(i=0; i<ninzu; i++){
        x = xTensu[i] - mean(ninzu, xTensu);
        y = yTensu[i] - mean(ninzu, yTensu);
        t1 += x * y;
        t2 += x * x;
        t3 += y * y;
    }

    return t1/sqrt(t2 * t3);
}
