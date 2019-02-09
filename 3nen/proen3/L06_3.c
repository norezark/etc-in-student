#include <stdio.h>
#include <float.h>

int main(void){
	int i;
	float z = 1.0, t;
	while(z/=2.0){
		t = z;
	}
	printf("%e\n", t);

	printf("FLT_MIN = %e\n", FLT_MIN);
	return 0;
}
