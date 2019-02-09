#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAdequate(int, char *[]);
mode_t permMode(char [], struct stat);
mode_t permNum(char []);
char permCtoI(char);


int main(int argc, char *argv[]){
    if(isAdequate(argc, argv))
    {
        fprintf(stderr, "But argument\n");
        exit(1);
    }
    if(strcmp(argv[1], "-h") == 0)
    {
        FILE *fp;
        if((fp = fopen("mychmod_help.txt", "r")) == NULL)
        {
            fprintf(stderr, "Can't open help\n");
            exit(1);
        }
        char str[256];
        while(fgets(str, 256, fp) != NULL)
        {
            printf(str);
        }
        fclose(fp);
        exit(0);
    }
    int i;
    for(i=2; i<argc; i++)
    {
        struct stat buf;
        if (stat(argv[i], &buf) != 0) {
            fprintf(stderr, "Cannot read i-node\n");
            exit(1);
        }
        char *str;
        str = strtok(argv[1], ",");
        while(1)
        {
            stat(argv[i], &buf);
            if (chmod(argv[i], permMode(str, buf)) != 0) {
                fprintf(stderr, "Cannot change mode\n");
            }
            if((str = strtok(NULL, ",")) == NULL) break;
        }
    }
    return 0;
}

int isAdequate(int argc, char *argv[])
{
    if(argc == 2 && (strcmp(argv[1], "-h") == 0)) return 0;

    if(argc < 3) return 1;
    if(strlen(argv[1]) == 3 && isdigit(argv[1][0]) && isdigit(argv[1][1]) && isdigit(argv[1][2]))
    {
        return 0;
    }
    else
    {
        int i = 0;
        while(argv[1][i] != '\0')
        {
            if(i%4 == 0)
            {
                if(argv[1][i] != 'a' && argv[1][i] != 'u' && argv[1][i] != 'g' && argv[1][i] != 'o') return 1;
            }
            else if(i%4 == 1)
            {
                if(argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '=') return 1;
            }
            else if(i%4 == 2)
            {
                if(argv[1][i] != 'r' && argv[1][i] != 'w' && argv[1][i] != 'x') return 1;
            }
            else if(i%4 == 3)
            {
                if(argv[1][i] != ',') return 1;
            }
            i++;
        }
        if(i % 4 != 3) return 1;

        return 0;
    }
}

mode_t permMode(char argv[3], struct stat buf)
{
    if(isdigit(argv[0]))
    {
        return permNum(argv);
    }
    else
    {
        char str[] = "000";
        if(argv[0] == 'a')
        {
            str[0] = str[1] = str[2] = permCtoI(argv[2]);
        }
        else
        {
            int t;
            if(argv[0] == 'u') t = 0;
            else if(argv[0] == 'g') t = 1;
            else if(argv[0] == 'o') t = 2;
            str[t] = permCtoI(argv[2]);
        }

        if(argv[1] == '+')
        {
            return buf.st_mode | permNum(str);
        }
        else if(argv[1] == '-')
        {
            return buf.st_mode & (~permNum(str) & 0777);
        }
        else if(argv[1] == '=')
        {
            return permNum(str);
        }
    }
}

char permCtoI(char c)
{
    switch(c)
    {
        case 'r':
            return '4';
        case 'w':
            return '2';
        case 'x':
            return '1';
    }
    return '\0';
}

mode_t permNum(char argv[3])
{
    return (mode_t)strtol(argv, NULL, 8);
}
