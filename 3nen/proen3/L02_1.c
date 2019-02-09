#include <stdio.h>

int main(void){
	int num, i, tosi;
	char name[15];
	float sintyo;
	double taiju;

	scanf("%d", &num);

	for(i=0; i<num; i++){
		scanf("%s%d%f%lf", name, &tosi, &sintyo, &taiju);
		printf("%s  %d  %.1f  %.1f\n", name, tosi, sintyo, taiju);
	}

	return 0;
}
