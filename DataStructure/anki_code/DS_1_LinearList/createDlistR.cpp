// D是双链表的double的意思
// R是尾插法的意思rear
#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode
{
    int data;
    struct DLNode *next;
    struct DLNode *prior;
} DLNode;

// 采用尾插法建立双链表
void creatDlistR01(DLNode *&L, int a[], int n)
{
    DLNode *s, *r;
    int i;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;
    for (i = 0; i < n; ++i)
    {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

//查找节点的算法
DLNode *findNode(DLNode *C, int x)
{
    DLNode *p = C->next;
    while (p != NULL)
    {
        /* code */
        if (p->data == x)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

/*插入结点的算法
s->next = p->next;
s->prior = p;
p->next = s;
s->next->prior = s;
*/

/*
q = p->next;
p->next = q->next;
q->next->prior = p;
free(q);
*/

/*逆置问题
for(int i = left, j = right; i < j; i++, j--){
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
*/

void reverse(int a[], int left, int right, int k)
{
    int temp;
    for (int i = left, j = right; i < left + k && i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

//数组前段移动到后端
void moveToEnd(int a[], int n, int k)
{
    reverse(a, 0, k - 1, k);
    reverse(a, 0, n - 1, k);
}

//循环左移p个位置
void moveP(int a[], int n, int p)
{
    reverse(a, 0, p - 1, p);
    reverse(a, p, n - 1, n - p);
    reverse(a, 0, n - 1, n);
}

// test
int largestPalindrome(int n)
{
    if (n == 1)
    {
        return 9;
    }
    int upper = pow(10, n) - 1;
    for (int left = upper;; left--)
    {
        long p = left;
        for (int x = left; x > 0; x /= 10)
        {
            p = p * 10 + x % 10;
        }
        for (long x = upper; x * x >= p; x--)
        {
            if (p % x == 0)
            {
                return p % 1337;
            }
        }
    }
}

int main()
{
    return 0;
}
