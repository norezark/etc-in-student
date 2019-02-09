//Time measurement of sorting programs
//N.SUN
//2018.5.18
//
//dataSet for testing:  dataSet1.txt, dataSet2.txt, dataSet3.txt
//answer file: time.csv

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sortLib.c"

#define N 2000000

void main()
{
    int data[N];

    int n;
    char fileName[50];

    printf("flieName: ");scanf("%s",fileName);
    printf("number of data: "); scanf("%d", &n);

    getData(data,n,fileName);

    timeMeasure(data, n);

}
