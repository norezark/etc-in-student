//hashing and finding alpha
//for 2018HI4 email list
//2018.7.10
//N.SUN

//to finish and hand in the function of hash5  till Aug.9,2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define H 47
#define N 46
#define K 60

typedef unsigned int INDEX;

INDEX hash1(char *s, int H_SIZE)
{
    int hash_val=0;

    s += 3;  //ignore the first 3 letters "hi1"  and the letters after "@"

    while(*s != '@')
        hash_val += *s++;

    return(hash_val % H_SIZE);
}//alpha=59.6%

INDEX hash2(char *s, int H_SIZE)
{
    int t = strlen(s);

    return((s[0] + 7 * s[6] + 53 * s[8] + t * s[t - 15]) % H_SIZE);

}//alpha=61.7%

INDEX hash3(char *s, int H_SIZE)
{
    unsigned int hash_val = 0;

    while(*s != '@')
        hash_val = (hash_val << 3) + *s++;

    return(hash_val % H_SIZE);
}//alpha=72.3%

INDEX hash4(int H_SIZE)
{
    return(rand() % H_SIZE);
} //alpha=68.1%

// a new hash function created by yourself
//INDEX hash5(char *s, int H_SIZE)
INDEX hash5(char *s, int H_SIZE, int b, int na)
{
    INDEX val = 0;

    double k[] =
    {
        0.06521739130434778,  0.021739130434782594,  0.0,  0.21739130434782605,  0.8260869565217391,  0.782608695652174,  0.8478260869565217,  0.7173913043478262,  0.8478260869565217,  0.7391304347826086,  0.8043478260869565,  0.8043478260869565,  0.8043478260869565
    };
    int i=0;
    while(i < 13)
        val = (val << b) + *s++*(int)(k[i++]*na);

    return val % H_SIZE;
} //alpha=xx.x%

void getStrings(char a[N][K])
{
    FILE *fp;
    int i,j;

    fp=fopen("2018HI4.txt","r");
    for(i = 0; i < N; i++) fscanf(fp,"%s",a[i]);//46 persons
    fclose(fp);
}

void initA(int b[])
{
    int i;
    for(i = 0; i < H; i++)  b[i]=0;
}

main()
{
    char list[N][K]; //emailList
    int HashList[H]; //list of hash values for the above emailList
    int i,x,count=0;
    int na;

    srand(47);
    //    printf("%40s : %s\n"," email "," Hash Value ");

    int b;
    while(scanf("%d", &na))
    {
        for(b=1; b<32; b++)
        {
            initA(HashList);
            getStrings(list);
            for(i = 0; i < N; i++)
            {
                x=hash5(list[i],H, b, na);
                //x=hash5(list[i],H);
                // x=hash4(H);

                //histogram
                HashList[x]++;

                //printf("%40s : %d\n",list[i],x);
            }

            //    printf("\n\n%5s : %s\n","index ","the number of the hashed items");
            for(i = 0; i < H; i++){
                //        printf(" %5d %5d \n", i, HashList[i]);

                if(HashList[i])
                    count++;
            }

            //printf("\n The number of the hashed items: %d \n", count);
            if((double)count/H >= 0.80)
            {
                printf("%d %d alpha = %lf\n", na, b, (double)(count)/H);
            //    return;
            }
            count=0;
        }
    }
}
