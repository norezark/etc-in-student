/* EX04 HI3 No.22  Name: 谷口怜遠 */
#include <stdio.h>
#define N 1000		//配列の最大要素数

// main関数を参考に，必要なプロトタイプ宣言を書きなさい
void input_data(int [], int*);
void show_data(int [], int);
void b_sort(int *, int);
void swap(int *, int *);

// main関数
int main(void){

		int data[N];		//データ配列data,最大要素数N個格納可能
		int n;				//実際に配列dataに格納するデータ個数

		input_data(data, &n);
		printf("入力直後のデータ:\n");
		show_data(data, n);

		b_sort(data,n);
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
//バブルソートを行う関数b_sortを書きなさい（昇順）
void b_sort(int data[N], int x){
	int i, j;
	
	for(i=0; i<x*(x-1)/2; i++){
		for(j=0; j<x-1; j++){
			if(data[j] > data[j+1])
				swap(&data[j], &data[j+1]);
		}
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
