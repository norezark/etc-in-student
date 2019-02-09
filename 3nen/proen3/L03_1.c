#include <stdio.h>
#include <string.h>

#define   MAX_LEN   100

int  main(void)
{
		int   len;
		char s[MAX_LEN], cpy[MAX_LEN], cat[MAX_LEN];

		printf("Input a string: ");
		scanf("%s", s);

		len = strlen(s);
		strcpy(cpy, s);
		strcpy(cat, s);
		strcat(cat, s);

		printf("Length = %d\nCopy = %s\nCat = %s\n", len, cpy, cat);

		return 0;
}

