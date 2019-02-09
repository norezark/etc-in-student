/* EX04 HI3 No.      Name:                       　*/
#include <stdio.h>
#define N 1000		//配列の最大要素数

// main関数を参考に，必要なプロトタイプ宣言を書きなさい
void input_data(int [], int*);
void show_data(int [], int);
void s_sort(int *, int);
void swap(int *, int *);

// main関数
int main(void){

		int data[N];		//データ配列data,最大要素数N個格納可能
		int n;				//実際に配列dataに格納するデータ個数

		input_data(data, &n);
		printf("入力直後のデータ:\n");
		show_data(data, n);

		s_sort(data,n);
		printf("並べ替え後のデータ:\n");
		show_data(data, n);

		return 0;
}

//データ配列data[N]にデータ入力を行う関数input_dataを書きなさい．
void input_data(int data[N], int *x){
	int i;

	printf("input number of data:");
	scanf("%d", x);
	printf("%d\n", *x);

	for(i=0; i<*x; i++)	scanf("%d", &data[i]);
}
//データ配列data[N]の値を画面表示する関数show_dataを書きなさい
void show_data(int data[N], int x){
	int i;

	for(i=0; i<x; i++)	printf("%5d", data[i]);
	printf("\n");
}
//選択ソートを行う関数s_sortを書きなさい（降順/昇順）
void s_sort(int data[N], int x){
	int i, j, target;
	
	for(i=0; i<x-1; i++){
		target = i;
		for(j=i; j<x; j++){
			if(data[j] > data[target])
				target = j;
		}
		swap(&data[i], &data[target]);
		printf("%d回目:", i+1);
		show_data(data, x);
	}
}
//与えられた２変数の値の入れ替えを行う関数swapを書きなさい
void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
