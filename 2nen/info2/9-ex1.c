#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define STRLEN_MAX 80
#define WORDNUM 5
#define TIME 5

int main(void){
	char words[][STRLEN_MAX] = {"astronaut", "benefit", "chocolate", 
								"daughter", "extraordinariness"};
	int r, i=1, j, c;
	char tmp[STRLEN_MAX]={"**************************\0"};

	srand((unsigned)time(NULL));
	r = rand() % WORDNUM;
	tmp[strlen(words[r])]='\0';
	printf("=== 文字当てゲーム ===\n単語は%d文字です。\n文字を%d回入力してください。\n", strlen(words[r]), TIME);
	while(i<=TIME){
		printf("%d回目: ", i);
		scanf("  %c", &c);
		if(c<'a'&&c>'z'){
			puts("不正な文字です");
		}else{
			for(j=0; j<strlen(words[r]); j++){
				if(c==words[r][j])	tmp[j]=c;
			}
			puts(tmp);
			i++;
		}
	}

	printf("答えを入力してください: ");
	scanf(" %s", tmp);
	if(strcmp(tmp, words[r])==0){
		puts("正解です。おめでとう！");
	}else{
		printf("残念・・正解は%sでした。\n", words[r]);
	}

	return 0;
}
