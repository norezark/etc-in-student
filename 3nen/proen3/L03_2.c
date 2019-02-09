#include        <stdio.h>
#include        <string.h>

#define MAX_LEN  100

char *myStrcpy(char *str1, const char *str2);

int  main(void)
{
		char s[MAX_LEN], cpy[MAX_LEN], mycpy[MAX_LEN];

		printf("Input a string: ");
		scanf("%s", s);

		strcpy(cpy, s);
		myStrcpy(mycpy, s);

		printf("cpy < s (strcpy)   = %s\n", cpy);
		printf("mycpy < s (myStrcpy) = %s\n", mycpy);

		return 0;
}

char *myStrcpy(char mycpy[MAX_LEN], const char s[MAX_LEN])
{
	int i=0;
	do{
		mycpy[i] = s[i];
	}while((s[i++]=='\0')==0);

	return mycpy;
}
