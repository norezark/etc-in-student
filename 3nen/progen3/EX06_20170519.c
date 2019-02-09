// HI3 NO.22  NAME 谷口怜遠
// // 2017.5.19
// // EX6_20170519.c

#include <stdio.h>

#define N 30

//メンバに height, weightを持つ構造体型をPhysiqueという名前で宣言しなさい
typedef struct physique{
	double height, weight;
}Physique;

//プロトタイプ宣言
void input_data(Physique [], int *);
void print_data(Physique [], int);
void s_sort_height(Physique [], int);
void s_sort_weight(Physique [], int);
void swap(Physique *, Physique *);

//main関数
int main(void){
	Physique data[N];
	int n;  //人数

	input_data(data, &n);
	printf("入力直後のデータ\n");
	print_data(data,n);

	s_sort_height(data,n);
	printf("身長基準並べ替え\n");
	print_data(data,n);

	s_sort_weight(data,n);
	printf("体重基準並べ替え\n");
	print_data(data,n);

	return 0;
}

//必要な関数を作成しなさい
void input_data(Physique data[N], int *n){
	scanf("%d", n);
	int i;
	for(i=0; i<*n; i++){
		scanf("%lf%lf", &data[i].height, &data[i].weight);
	}
}
void print_data(Physique data[N], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d人目の身長,体重: %.1f %.1f\n", i+1, data[i].height, data[i].weight);
	}
}
void s_sort_height(Physique data[N], int n){
	int i, j, target;
	
	for(i=0; i<n-1; i++){
		target = i;
		for(j=i; j<n; j++){
			if(data[j].height > data[target].height)
				target = j;
		}
		swap(&data[i], &data[target]);
		//printf("%d回目:", i+1);
		//print_data(data, n);
	}
}
void s_sort_weight(Physique data[N], int n){
	int i, j, target;
	
	for(i=0; i<n-1; i++){
		target = i;
		for(j=i; j<n; j++){
			if(data[j].weight > data[target].weight)
				target = j;
		}
		swap(&data[i], &data[target]);
		//printf("%d回目:", i+1);
		//print_data(data, n);
	}
}
void swap(Physique *x, Physique *y){
	Physique tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
