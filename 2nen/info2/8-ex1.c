#include <stdio.h>
#define ALPHA 'Z'-'A'+1

int main(void){
	char ch;
	int alp[ALPHA]={}, max=0, i;

	do{
		ch=getchar();
		if(ch>='a'&&ch<='z') ch-='a'-'A';
		alp[ch-'A']++;
	}while(ch!=EOF);

	putchar('\n');
	for(i=0; i<ALPHA; i++){
		printf("%c:%4d  ", 'A'+i, alp[i]);
		if((i+1)%6==0) putchar('\n');
		if(max<alp[i]) max=alp[i];
	}
	
	putchar('\n');
	printf("一番多かった文字:");
	for(i=0; i<ALPHA; i++){
		if(max==alp[i])
			printf(" %c", 'A'+i);
	}
	putchar('\n');

	return 0;
}
