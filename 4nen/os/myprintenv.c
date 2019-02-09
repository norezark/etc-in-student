#include <stdio.h>
#include <string.h>

int main(int ac, char *av[], char *ev[])
{
    char delimiter = '\n';

    if(ac >= 2)
    {
        if(strcmp(av[1], "--help") == 0)
        {
            FILE *fp;
            if((fp = fopen("myprintenv_help.txt", "r")) == NULL)
            {
                fprintf(stderr, "Can't open help\n");
                return 1;
            }
            char str[256];
            while(fgets(str, 256, fp) != NULL)
            {
                printf(str);
            }
            fclose(fp);

            return 0;
        }
        else if(strcmp(av[1], "-0") == 0 || strcmp(av[1], "--null") == 0)
        {
            delimiter = '\0';
            if(ac == 2) ac = 1;
        }
    }

    int i, c;
    char envname[256], envval[4096];

    for(i=0; ev[i]!=NULL; i++)
    {
        if(ac == 1)
        {
            printf("%s%c", ev[i], delimiter);
        }
        else
        {
            sscanf(ev[i], "%[^=]=%s", envname, envval);
            c = 0;
            while(++c < ac)
            {
                if(strcmp(envname, av[c]) == 0)
                {
                    printf("%s%c", envval, delimiter);
                    break;
                }
            }
        }
    }

    return 0;
}
