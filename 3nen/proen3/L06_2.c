#include <stdio.h>

union float_t{
	float x;
	unsigned char y[4];
};

int main(void){
	int i;
	union float_t f;
	char t[4];

	for(i=0; i<4; i++){
		scanf("%02x", &t[i]);
	}
	
	for(i=0; i<4; i++){
		f.y[i] = t[3-i];
	}

	printf("%.7f\n", f.x);

	return 0;
}
