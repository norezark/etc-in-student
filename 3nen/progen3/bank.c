#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLIM 22
#define DATAFILE "user.bin"
#define PASSCODE 111

typedef struct user {
    int id;
    char name[STRLIM];
    int balance;
    char passwd[STRLIM];
    struct user *next;
} User;

void touroku();
User *auth();
void zandaka();
void hikidasi();
void yokin();
int syuryo();
void allocerror();
User *search(int);

User *users;
int accnum = 0;

int main(void){
    FILE *fp;
    int i, j, mode = 0, fsize;
    char tmp[256];
    User *now = NULL, *temp;
    
    if((fp = fopen(DATAFILE, "rb")) == NULL){
        printf("データファイルが開けません。\n");
        return 0;
    }else{
        fseek(fp, 0, SEEK_END);
        fgetpos(fp, &fsize);
        rewind(fp);
        accnum = fsize / sizeof(User);
        while(fsize > 0){
            if((temp = (User *)malloc(sizeof(User))) == NULL) allocerror();
            fread(temp, sizeof(User), 1, fp);
            if(accnum * sizeof(User) == fsize){
                users = temp;
            }else{
                now->next = temp;
            }
            now = temp;
            now->next = NULL;
            fsize -= sizeof(User);
        }
    }
    fclose(fp);

    while(1){
        printf("動作を選んでください。\n1: ユーザー登録\n2: 残高照会\n3: 引き出し\n4: 預金\n5: 終了\n");
        scanf(" %d", &mode);
        if(mode>5 || mode<1){
            printf("正しい数字を入力してください。\n");
        }else{
            switch(mode){
                case 1:
                    touroku();
                    break;
                case 2:
                    zandaka();
                    break;
                case 3:
                    hikidasi();
                    break;
                case 4:
                    yokin();
                    break;
            }
        }
        if(mode == 5 && syuryo()){
            for(i = 1; i <= accnum; i++){
                now = search(i);
                printf("ID: %16d | NAME: %16s | BALANCE: %16d | passwd: %16s\n", now->id, now->name, now->balance, now->passwd);
            }
            break;
        }
        printf("選ばれた動作を終了しました。\n");
    }

    if((fp = fopen(DATAFILE, "wb")) == NULL){
        printf("データファイルが開けません。\n");
        exit(0);
    }else{
        now = users;
        while(now != NULL){
            fwrite(now, sizeof(User), 1, fp);
            now = now->next;
        }
    }

    fclose(fp);

    i = accnum;
    while(i){
        now = search(i--);
        if(now != NULL) free(now);
    }
        
    return 0;
}

int syuryo(){
    int pass;
    printf("パスを入力してください。:");
    scanf("%d", &pass);
    if(pass == PASSCODE){
        printf("プログラムを終了します。\n");
        return 1;
    }else{
        printf("パスが違います。\n");
        return 0;
    }
}

User *search(int num){
    if(num <= 0 || num > accnum){
        return NULL;
    }else{
        User *t = users;
        while(--num > 0){
            t = t->next;
        }
        return t;
    }
}

void touroku(){
    printf("ユーザー登録を選びました。\n");

    User *temp;
    if((temp = (User *)malloc(sizeof(User))) == NULL){
        allocerror();
    }else{
        if(accnum == 0){
            users = temp;
        }else{
            search(accnum)->next = temp;
        }
        printf("\t登録するユーザーの情報を入力してください。\n");
        printf("\t名前(～%d文字) :", STRLIM-1);
        scanf("%*[ \n]%21[^ \n]", &temp->name);
        printf("\tパスワード(～%d文字) :", STRLIM-1);
        scanf("%*[ \n]%21[^ \n]", &temp->passwd);
        temp->id = ++accnum;
        temp->balance = 0;
        temp->next = NULL;
        printf("\tID:%d\t名前:%s\tで登録されました。\n", temp->id, temp->name);
    }
     
    return;
}

User *auth(){
    int id;
    char passwd[STRLIM];
    while(1){
        printf("\t口座のIDを入力してください。(終了:0) :");
        scanf("%*[ \n]%d", &id);
        if(id == 0){
            break;
        }else if(id>accnum || id<0){
            printf("\t正しいIDを入力してください。%d\n", accnum);
        }else{
            User *now;
            if((now = search(id)) == NULL){
                printf("\tIDが存在しません。\n");
            }else{
                printf("\tパスワードを入力してください。 :");
                scanf("%*[ \n]%25[^ \n]", passwd);
                if(strcmp(now->passwd, passwd)){
                    printf("\tパスワードが違います。\n");
                }else{
                    printf("\t%sさんの口座です。現在の残高は%d円です。\n", now->name, now->balance);
                    return now;
                }
            }
        }
    }

    return NULL;
}

void zandaka(){
    printf("残高照会を選びました。\n");

    auth();

    return;
}
void hikidasi(){
    printf("引き出しを選びました。\n");
    
    int balance = 0;
    User *t;
    if((t = auth()) == NULL) return;
    while(1){
        printf("\t引き出しの額を入力してください。 :");
        scanf("%d", &balance);
        if(balance > t->balance || balance < 0){
            printf("\t正しい額を入力してください。\n");
        }else{
            t->balance -= balance;
            printf("\t%d円引き出しされました。現在の残高は%d円です。\n", balance, t->balance);
            break;
        }
    }

    return;
}

void yokin(){
    printf("預金を選びました。\n");

    int balance;
    User *t;
    if((t = auth()) == NULL) return;
    while(1){
        printf("\t預金の額を入力してください。 :");
        scanf("%*[ \n]%d", &balance);
        if(balance < 0){
            printf("\t正しい額を入力してください。\n");
        }else{
            t->balance += balance;
            printf("\t%d円預金されました。現在の残高は%d円です。\n", balance, t->balance);
            break;
        }
    }

    return;
}

void allocerror(){
    fprintf(stderr, "function alloc error\n");
    int i = accnum;
    User *now;
    while(i){
        now = search(i--);
        free(now);
    }
    exit(1);
}
