#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int BOOL;

typedef struct lnode
{
    T Element;
    struct lnode *Next;
}LNode;

typedef struct list
{
    int Size;
    LNode *First;
}List;

void CreatList(List *list)
{
    list -> Size = 0;
    list -> First = NULL;
}

BOOL IsEmpty(List list)
{
    return list.Size == 0;
}

// BOOL Append(List *list, T x)
// {
//     LNode *q;
//     LNode *p = (LNode*)malloc(sizeof(LNode));
//     p -> Element = x;
//     p -> Next = NULL;
//     if(IsEmpty(*list))
//     {
//         list -> First = p;
//     }
//     else
//     {
//         q = list -> First;
//         while(q -> Next)
//             q = q -> Next;
//         q -> Next = p;
//     }
//     list -> Size ++;
//     return TRUE;
// }

LNode* set_pos(List list, int pos)
{
    int i;
    LNode *q = list.First;
    for(i = 0; i < pos; ++i)
        q = q -> Next;
    return q;
}

BOOL Insert(List *list, int pos, T x)
{
    LNode *p;
    LNode *q = list -> First;
    if(pos < 0 || pos > list -> Size)
        return FALSE;
    p = (LNode*)malloc(sizeof(LNode));
    p -> Element = x;
    p -> Next = NULL;
    if(pos == 0)
    {
        p -> Next = list -> First;
        list -> First = p;
    }
    else
    {
        q = set_pos(*list, pos - 1);
        p -> Next = q -> Next;
        q -> Next = p;
    }
    list -> Size ++;
    return TRUE;
}

BOOL Append(List *list, T x)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p -> Element = x;
    p -> Next = list -> First;
    list -> First = p;
}
void main()
{
    List list;
    CreatList(&list);
    // Insert(&list, 0, 5);
    // Insert(&list, 0, 5);
    // Insert(&list, 0, 5);
    // Insert(&list, 0, 8);
    // Insert(&list, 0, 2);
    for(int i = 0; i < 10; ++i)
        Append(&list, i);
    LNode *q = list.First;
    while (q)   
    {
        printf("%d ", q -> Element);
        q = q -> Next;
    }
    
}
