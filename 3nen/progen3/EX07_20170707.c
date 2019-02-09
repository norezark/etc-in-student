#include <stdio.h>

void wc(FILE *fp, int wc[3]){
    int i;
    int f = 1;
    char ch;

	while((ch = fgetc(fp)) != EOF){
		if(ch == '\n') wc[0]++;
        if(ch!='\n' && ch!=' ' && ch!='\t') f = 1;
        if((ch=='\n' || ch==' ' || ch=='\t') && f==1){
            f = 0;
            wc[1]++;
        }
		wc[2]++;
	}
    for(i=0; i<3; i++){
	    printf("%7d ", wc[i]);
    }
}

int main(int argc, char *argv[]){
    int w[3] = {0}; //gyou, tango, mozi
	if(argc == 1){
		wc(stdin, w);
        puts("");
	}else{
        FILE *fp;
        int s[3] = {0};
        int i, j;
        for(i=0; i<argc-1; i++){
			if((fp = fopen(*++argv, "r")) == NULL){
				fprintf(stderr, "%sを開けませんでした\n", *argv);
			}else{
				wc(fp, w);
                puts(*argv);
                for(j=0; j<3; j++){
                    s[j] += w[j];
                    w[j] = 0;
                }
                fclose(fp);
			}
		}

        if(argc >= 3){
            for(i=0; i<3; i++){
                printf("%7d ", s[i]);
            }
            puts("合計");
        }
	}

	return 0;
}
