/* EX03 HI3_22  Taniguchi Reon */
#include <stdio.h>

//Prototype Definition
void swap(int *, int *);

//function main()
int main(void){
		int input1, input2;

		printf("input two integer number:");
		scanf("%d%d", &input1, &input2);	
		printf("%7d %7d\n", input1, input2);


		//call swap() function
		swap(&input1, &input2);

		printf("%7d %7d\n", input1, input2);


		return 0;
}

//function swap()
void swap(int *x, int *y){
		int tmp;
		tmp = *x;
		*x = *y;
		*y = tmp;
}
