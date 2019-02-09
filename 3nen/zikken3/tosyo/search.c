#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOOKMAX 500

typedef struct {
    int id;
    char title[30];
    char author[30];
    int isLend;
} Book;

void readData();
void bookSearch();

Book books[BOOKMAX];

int main(void){
    while(1) bookSearch();

    return 0;
}

void readData(){
    FILE *fp;
    int i = 0;

    if((fp = fopen("data", "r")) == NULL){
        printf("file open error\n");
        exit(1);
    }

    while(fscanf(fp, "%d %s %s %d", &books[i].id, books[i].title, books[i].author, &books[i].isLend) != EOF){
        //printf("%d %s %s %d\n", books[i].id, books[i].title, books[i].author, books[i].isLend);
        i++;
    }

    fclose(fp);
}

void bookSearch(){
    char stitle[30];
    int i;
    printf("search: ");
    scanf("%29s", stitle);
    readData();
    for(i = 0; i < BOOKMAX; i++){
        if(strcmp(books[i].title, stitle) == 0){
            printf("id:%d title:%s author:%s isLend:%d\n", books[i].id, books[i].title, books[i].author, books[i].isLend);
            return;
        }
    }
    printf("couldn't find\n");
}
