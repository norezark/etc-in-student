#include <stdio.h>
#include <math.h>

#define STUDENT_MAX 50
#define KYOUKA 5
#define LINE_MAX 256

int students;
int tensu[KYOUKA][STUDENT_MAX];

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
    //scanf("%d %d", &k1, &k2);
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
    return 0;
}

void InputData(char *fname){
    FILE *fp;
    char t[LINE_MAX];
    int f = 0, i = 0;

    if((fp = fopen(fname, "r")) == NULL){
        printf("ファイルが開けません。");
    }else{
        while(fgets(t, LINE_MAX, fp) != NULL){
            if(f == 0){
                f = 1;
                sscanf(t, "%d\n", &students);
            }else{
                sscanf(t, "%d %d %d %d %d\n", &tensu[0][i], &tensu[1][i],
                                              &tensu[2][i], &tensu[3][i],
                                              &tensu[4][i]);
                i++;
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
