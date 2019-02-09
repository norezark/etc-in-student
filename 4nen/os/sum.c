#include <stdio.h>

int main(void)
{
    int t = -1, sum = 0;
    while(t != 0)
    {
        scanf(" %d", &t);
        sum += t;
    }

    printf("%d\n", sum);

    return 0;
}
