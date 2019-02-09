#include <stdio.h>

int main(int argc, char *argv[]){
	sleep(atoi(argv[1]));

	printf("%s秒経過しました\n", argv[1]);

	return 0;
}
