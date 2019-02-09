#include        <stdio.h>
#include        <string.h>

#define MAX_LEN  100

char *myStrcat(char *str1, const char *str2);

int  main(void)
{
		char s[MAX_LEN], cat[MAX_LEN], mycat[MAX_LEN];
		
		printf("Input a string1: ");
		scanf("%s", s);

		printf("Input a string2: ");
		scanf("%s", cat);
		
		strcpy(mycat, cat);
		strcat(cat, s);
		myStrcat(mycat, s);

		printf("string1 + string2 (strcat)   = %s\n", cat);
		printf("string1 + string2 (myStrcat) = %s\n", mycat);

		return 0;
}

char *myStrcat(char mycat[MAX_LEN], const char s[MAX_LEN])
{
	int i=0, j;
	while((mycat[i]=='\0')==0)	i++;
	for(j=0; (s[j]=='\0')==0; j++)
		mycat[i+j] = s[j];
	mycat[i+j] = '\0';
	return mycat;
}
