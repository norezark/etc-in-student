/* EX02 HI3_22  Taniguchi Reon */
#include <stdio.h>

//Prototype Definition
void print_X(int);

//function main()
int main(void){
		int size;

		printf("input size of draw (integer number):");
		scanf("%d", &size);


		//call print_X() function
		print_X(size);

		return 0;
}

//function print_X()
void print_X(int size){
		int i,j;
		for(i=0; i<size; i++){
			for(j=0; j<size; j++){
				if(j==i || j==(size-i-1)){
					putchar('*');
				}else{
					putchar(' ');
				}
			}
			putchar('\n');
		}
}
