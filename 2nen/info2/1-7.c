#include <stdio.h>

int main(){
	double da,db;
	puts("実数daを入力してください:");
	scanf("%lf", &da);
	puts("実数dbを入力してください:");
	scanf("%lf", &db);
	printf("da + db: %6.2lf\nda - db: %6.2lf\nda * db: %6.2lf\nda / db: %6.2lf\n", da+db, da-db, da*db, da/db);

	return 0;
}
