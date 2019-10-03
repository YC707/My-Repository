#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int BOOL;

typedef struct snode
{
    T Element;
    struct snode *Next;
}SNode;

typedef struct stack
{
    SNode *Top;
}Stack;

void CreatStack(Stack *s)
{
    s -> Top = NULL;
}

BOOL IsEmpty(Stack s)
{
    if(!s.Top)
        return TRUE;
    return FALSE;
}

BOOL Push(Stack *s, T x)
{
    SNode *p = (SNode*)malloc(sizeof(SNode));
    p -> Element = x;
    p -> Next = s -> Top;
    s -> Top = p;
    return TRUE;
}

BOOL Pop(Stack *s)
{
    if(IsEmpty(*s))
        return FALSE;
    SNode *p = s -> Top;
    s -> Top = p -> Next;
    free(p);
    return TRUE;
}

BOOL StackTop(Stack s, T *x)
{
    if(IsEmpty(s))
        return FALSE;
    *x = s.Top -> Element;
    return TRUE;
}

void main()
{
    Stack s;
    CreatStack(&s);

    Push(&s, 12);
    Push(&s, 5);

    T x;
    StackTop(s, &x);
    Pop(&s);
    printf("%d ", x);
}
