#include <stdio.h>
#include <stdlib.h>

union float_t{
	float x;
	unsigned char y[4];
};

int main(void){
	union float_t f;
	scanf("%f", &f.x);

	int i;
	for(i=3; i>=0; i--){
		printf("%02X", f.y[i]);
	}
	puts("");

	return 0;
}
