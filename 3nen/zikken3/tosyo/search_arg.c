#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOOKMAX 1000

typedef struct {
    int id;
    char title[30];
    char author[30];
    int isLend;
} Book;

void readData();
void bookSearch();

Book books[BOOKMAX];

int main(int argc, char *argv[]){
    if(argc == 2 && strlen(*++argv) <= 29) {
        bookSearch(*argv);
    }else{
        puts("argument error");
        exit(1);
    }

    return 0;
}

void readData(){
    FILE *fp;
    int i = 0;

    if((fp = fopen("a2.txt", "r")) == NULL){
        //printf("file open error\n");
        exit(1);
    }

    while(fscanf(fp, "%d%s%s%d", &books[i].id, books[i].title, books[i].author, &books[i].isLend) != EOF){
        i++;
    }

    fclose(fp);
}

void bookSearch(char *word){
    int i, d = 0;
    readData();
    for(i = 0; i < BOOKMAX; i++){
        if(strstr(books[i].title, word) != NULL){
            printf("%d %s %s %d\n", books[i].id, books[i].title, books[i].author, books[i].isLend);
        }else{
            d++;
        }
    }
    if(d == i) exit(1);
    //printf("couldn't find\n");
}
