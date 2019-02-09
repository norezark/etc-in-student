#include <stdio.h>

FILE *fp;
char *filed = "%s\t%s\t%s\t%s\t%s";
char a[9];
char b[7];
char c[9];
char d[10];
char e[8];

int main(void){
	fp = fopen("data1.txt", "r");
	while(fscanf(fp, filed, a, b, c, d, e) != EOF){
		printf(filed , a, b, c, d, e);
		putchar('\n');
	}
	fclose(fp);

	return 0;
}
