#include <stdio.h>

int main(void){
	int x, i, a;

	while(1){
		printf("大きさを入力してください(最大20):");	scanf("%d", &x);

		if(x<1 || x>20){
			puts("値の範囲を超えています");
			continue;
		}
		break;
	}

	for(i=1; i<=x+2; i++){
		switch(i){
		case 1:
				printf("    |");
				for(a=1; a<=x; a++)
					printf("%4d", a);
				break;
			case 2:
				for(a=1; a<=x*4; a++){
					if(a==5) putchar('+');
					putchar('-');
				}
				break;
			default:
				printf("%4d|", i-2);
				for(a=1; a<=x; a++)
					printf("%4d", a*(i-2));
				break;
		}
		puts("");
	}

	return 0;
}
