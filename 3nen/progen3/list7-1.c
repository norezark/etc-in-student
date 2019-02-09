#include <stdio.h>

int main(void){
	struct xy {
		int x;
		double y;
	};
	struct xy s = {1, 1};
	struct xy t = s;
	struct xy *u;

	printf("s.x=%d\n", s.x);
	printf("s.y=%f\n", s.y);
	printf("t.x=%d\n", t.x);
	printf("t.y=%f\n", t.y);

	u = &s;

	printf("u->x=%d\n", u->x);
	printf("u->y=%f\n", u->y);

	return 0;
}
