#include <stdio.h>
#define STRLEN_MAX 80

void capitalize(char words[][STRLEN_MAX], int n){
	int i;
	for(i=0; i<n; i++){
		if((words[i][0] >= 'a') && (words[i][0] <= 'z'))
			words[i][0] += 'A'-'a';
	}
}

int main(void){
	char cs[][STRLEN_MAX] = {"east", "west", "123", "Kumamon"};
	int i, num=sizeof(cs)/sizeof(cs[0]);

	puts("初期状態:");
	for(i=0; i<num; i++)
		puts(cs[i]);

	capitalize(cs, num);

	puts("capitalize関数実行後:");
	for(i=0; i<num; i++)
		puts(cs[i]);
	
	return 0;
}
