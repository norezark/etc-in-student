#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Term, Insert, Delete, Print, Clear
} Menu;

typedef struct __node {
    int no;
    char name[10];
    struct __node *next;
} Node;

void SetNode(Node *x, int no, const char *name, const Node *next)
{
    x->no = no;
    x->next = next;
    strcpy(x->name, name);
}

Node *AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

void InsertNode(Node **top, int no, const char *name)
{
    Node *ptr = *top;
    *top = AllocNode();
    SetNode(*top, no, name, ptr);
}

void AppendNode(Node **top, int no, const char *name)
{
    if(*top == NULL){
        InsertNode(top, no, name);
    }else if(strcmp((*top)->name, name) > 0){
        InsertNode(top, no, name);
    }else{
        Node *ptr = *top;
        while(ptr->next != NULL && strcmp(ptr->name, name) < 0){
            ptr = ptr->next;
        }
        Node *t = AllocNode();
        SetNode(t, no, name, ptr->next);
        ptr->next = t;
    }
}

void DeleteNode(Node **top)
{
    if(*top != NULL){
        Node *ptr = (*top)->next;
        free(*top);
        *top = ptr;
    }
}

void ClearList(Node **top)
{
    while(*top != NULL)
        DeleteNode(top);
}

void PrintList(const Node **top)
{
    Node *ptr = *top;

    puts("[一覧表]");
    while(ptr != NULL){
        printf("%5d %-10.10s\n", ptr->no, ptr->name);
        ptr = ptr->next;
    }
}

void InitList(Node **top)
{
    *top = NULL;
}

void TermList(Node **top)
{
    ClearList(top);
}

Node Read(const char *message)
{
    Node temp;

    printf("%sするデータを入力してください。\n", message);
    printf("番号: "); scanf("%d", &temp.no);
    printf("名前: "); scanf("%s", temp.name);

    return temp;
}

Menu SelectMenu(void)
{
    int ch;

    do{
        printf("\n(1) ノードを挿入\n");
        printf("(2) 先頭ノードを削除    (3) 全ノードを表示\n");
        printf("(4) 全ノードを削除  (0)処理終了\n");
        scanf("%d", &ch);
    } while(ch<Term || ch>Clear);
    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    Node *list;

    InitList(&list);

    do{
        Node x;
        switch (menu = SelectMenu()){
            case Insert :   x = Read("挿入");
                            AppendNode(&list, x.no, x.name);
                            break;
            case Delete :   DeleteNode(&list);
                            break;
            case Print  :   PrintList(&list);
                            break;
            case Clear  :   ClearList(&list);
                            break;
        }
    } while(menu != Term);

    TermList(&list);

    return 0;
}
