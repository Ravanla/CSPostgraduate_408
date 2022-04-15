// D是双链表的double的意思
// R是尾插法的意思rear
#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode{
    int data;
    struct DLNode *next;
    struct DLNode *prior;
}DLNode;

void creatDlistR01(DLNode *&L, int a[], int n){
    DLNode *s, *r;
    int i;
    L = (DLNode*)malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;
    for(i = 0; i < n; ++i){
        s = (DLNode*)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

int main(){
    return 0;
}
