#include <stdio.h>
#include <string.h>
#define PASSWORD "abc123"

int main(void){
	char pwd[80];

	while(1){
		printf("Input password: ");
		scanf("%s", pwd);
		if(strcmp(PASSWORD, pwd)){
			puts("Wrong!");
		}else{
			puts("OK.");
			break;
		}
	}

	return 0;
}
