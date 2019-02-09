#include <stdio.h>

//Prototype Definition

void func1(int, int);
void func2(int *, int);
int  func3(int, int);

//function main()
int main(void){
		int data1_main, data2_main;

		// func1()
		func1(5,10);
		putchar('\n');

		data1_main = 50;
		data2_main = 10;
		func1(data1_main, data2_main);
		printf("[main_func1]%7d %7d\n",data1_main, data2_main);
		putchar('\n');

		// func2()
		data1_main = 500;
		data2_main = 100;
		func2(&data1_main, data2_main);
		printf("[main_func2]%7d %7d\n",data1_main, data2_main);
		putchar('\n');

		// func3()
		data1_main = 50000;
		data2_main = 10000;
		printf("[main_func3]%7d %7d\n",data1_main, data2_main);
		printf("[main_func3]%7d + %7d = %7d\n", data1_main, data2_main, func3(data1_main, data2_main));
		putchar('\n');

		return 0;
}

//function func1()
void func1(int p1, int p2){
		printf("[func1_1]%7d %7d\n",p1, p2);
		p1 = p1 + p2;
		printf("[func1_2]%7d %7d\n",p1, p2);
}

//function func2()
void func2(int *p1, int p2){
		printf("[func2_1]%7d %7d\n", *p1, p2);
		*p1 = *p1 + p2;
		printf("[func2_2]%7d %7d\n", *p1, p2);
}

//function func3()
int  func3(int p1, int p2){
		int sum;
		printf("[func3_1]%7d %7d\n", p1, p2);
		sum = p1 + p2;
		printf("[func3_2]%7d+%7d=%7d\n", p1, p2, sum);

		return(sum);
}
