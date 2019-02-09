#include <stdio.h>

int main(void){
		int a, b, ans;
		char op;

		while(1){
				scanf("%d %s %d", &a, &op, &b);

				if(op=='?') break; else{
						switch(op){
								case '+':
										ans = a+b;	break;
								case '-':
										ans = a-b;	break;
								case '*':
										ans = a*b;	break;
								case '/':
										ans = a/b;	break;
						}
				}

				printf("%d\n", ans);
		}

		return 0;
}
