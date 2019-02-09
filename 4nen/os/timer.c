#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pid = fork();
    if(pid < 0)
    {
        printf("プロセスエラー\n");
        exit(1);
    }
    else if(pid >= 1)
    {
        exit(0);
    }
    else if(pid == 0)
    {
        if(argc==4 && strcmp(argv[1], "-s")==0)
        {
            int i;
            for(i=1; i<=atoi(argv[2]); i++)
            {
                sleep(atoi(argv[3]));
                printf("%d秒\n", i * atoi(argv[3]));
            }
            printf("完了\n");
            exit(0);
        }
        else if(argc >= 2)
        {
            int i, c = 0, t, f = 1;
            while(f)
            {
                sleep(1);
                c++;
                f = 0;
                for(i=1; i<argc; i++)
                {
                    t = atoi(argv[i]);
                    if(c == t) printf("%d秒\n", c);
                    else if(c < t) f = 1;
                }
            }
            printf("完了\n");
            exit(0);
        }
        else if(argc == 1)
        {
            printf("%s\n", argv[0]);
            printf("    使い方\n");
            printf("%s [time1][time2]...\n", argv[0]);
            printf("    time1秒後、time2秒後、...に通知\n");
            printf("%s -s [count][time]\n", argv[0]);
            printf("    time秒ごとにcount回通知\n");
            exit(0);
        }
        else
        {
            printf("引数エラー\n");
            exit(1);
        }
    }

    return 0;
}
