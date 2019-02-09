#include <stdio.h>
#include <stdlib.h>

#define TIE 0
#define WIN 1
#define LOSE -1
#define ARR_MAX 100

int setPlayerHand(){
	char s[ARR_MAX];
	int h;
	printf("あなたの手を入力してください(グー:1 チョキ:2 パー:3): ");
	scanf(" %s", s);
	h = atoi(s);

	if(h==1||h==2||h==3){
		return h;
	}else{
		puts("値が正しくありません");
		setPlayerHand();
	}
}

int setComputerHand(){
	return random()%3+1;
}

int judge(int player, int computer){
	if(player-1 == computer-1)
		return TIE;
	else if(player-1 == (computer)%3)
		return LOSE;
	else
		return WIN;
}

void printResult(int result, int player, int computer){
	char hands[3][ARR_MAX] = {"グー", "チョキ", "パー"};
	printf("あなた: %s\nコンピューター: %s\n", hands[player-1], hands[computer-1]);

	if(result == TIE)
		puts("あいこです。");
	else if(result == WIN)
		puts("あなたの勝ちです。");
	else
		puts("あなたの負けです。");
}

int main(void){
	int player, computer, result;


	do{
		srandom(time(0));
		computer = setComputerHand();
		player = setPlayerHand();
		result = judge(player, computer);
		printResult(result, player, computer);
	}while(result == TIE);

	return 0;
}
